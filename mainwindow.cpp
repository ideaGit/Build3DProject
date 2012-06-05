/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
**
****************************************************************************/
#include "PreDefs.h"
#include "mainwindow.h"
#include "colorswatch.h"
#include "toolbar.h"
#include "AdapterWidget.h"
#include "BuildingData.h"
#include "textio.h"
#include <QtGui>


Q_DECLARE_METATYPE(QDockWidget::DockWidgetFeatures)

MainWindow::MainWindow(const QMap<QString, QSize> &customSizeHints,
                        QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    setObjectName("MainWindow");
    setWindowTitle("3D Building Reconstruction");

	_glWidget = new ViewerQT;
    _glWidget->setMinimumSize(400, 400);
    setCentralWidget(_glWidget);

    setupToolBar();
    setupMenuBar();
    setupDockWidgets(customSizeHints);

    statusBar()->showMessage(tr("Status Bar"));

	//
	m_pBuildingData = new CBuildingData;
}

void MainWindow::actionTriggered(QAction *action)
{
    qDebug("action '%s' triggered", action->text().toLocal8Bit().data());
}

void MainWindow::setupToolBar()
{
	setIconSize(QSize(32, 32));
	
	QToolBar* toolBar1 = addToolBar(tr("Tool Bar 1"));
	QAction* openAction = new QAction(QIcon("./res/open.png"), tr("&Open"), this);
	connect(openAction, SIGNAL(triggered()), SLOT(loadmodel()));

	toolBar1->addAction(openAction);

    //for (int i = 0; i < 3; ++i) {
    //    ToolBar *tb = new ToolBar(QString::fromLatin1("Tool Bar %1").arg(i + 1), this);
    //    toolBars.append(tb);
    //    addToolBar(tb);
    //}
}

void MainWindow::setupMenuBar()
{
    QMenu *menu = menuBar()->addMenu(tr("&File"));

	QAction *action = menu->addAction(tr("Load model"));
	connect(action, SIGNAL(triggered()), this, SLOT(loadmodel()));

    action = menu->addAction(tr("Save model"));
    connect(action, SIGNAL(triggered()), this, SLOT(savemodel()));

	menu->addSeparator();

    action = menu->addAction(tr("Switch layout direction"));
    connect(action, SIGNAL(triggered()), this, SLOT(switchLayoutDirection()));

    menu->addSeparator();

    menu->addAction(tr("&Quit"), this, SLOT(close()));

    mainWindowMenu = menuBar()->addMenu(tr("Main window"));

    action = mainWindowMenu->addAction(tr("Animated docks"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & AnimatedDocks);
    connect(action, SIGNAL(toggled(bool)), this, SLOT(setDockOptions()));

    action = mainWindowMenu->addAction(tr("Allow nested docks"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & AllowNestedDocks);
    connect(action, SIGNAL(toggled(bool)), this, SLOT(setDockOptions()));

    action = mainWindowMenu->addAction(tr("Allow tabbed docks"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & AllowTabbedDocks);
    connect(action, SIGNAL(toggled(bool)), this, SLOT(setDockOptions()));

    action = mainWindowMenu->addAction(tr("Force tabbed docks"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & ForceTabbedDocks);
    connect(action, SIGNAL(toggled(bool)), this, SLOT(setDockOptions()));

    action = mainWindowMenu->addAction(tr("Vertical tabs"));
    action->setCheckable(true);
    action->setChecked(dockOptions() & VerticalTabs);
    connect(action, SIGNAL(toggled(bool)), this, SLOT(setDockOptions()));

    QMenu *toolBarMenu = menuBar()->addMenu(tr("Tool bars"));
    for (int i = 0; i < toolBars.count(); ++i)
        toolBarMenu->addMenu(toolBars.at(i)->menu);

    dockWidgetMenu = menuBar()->addMenu(tr("&Dock Widgets"));
}

void MainWindow::setDockOptions()
{
    DockOptions opts;
    QList<QAction*> actions = mainWindowMenu->actions();

    if (actions.at(0)->isChecked())
        opts |= AnimatedDocks;
    if (actions.at(1)->isChecked())
        opts |= AllowNestedDocks;
    if (actions.at(2)->isChecked())
        opts |= AllowTabbedDocks;
    if (actions.at(3)->isChecked())
        opts |= ForceTabbedDocks;
    if (actions.at(4)->isChecked())
        opts |= VerticalTabs;

    QMainWindow::setDockOptions(opts);
}

void MainWindow::savemodel()
{
    QString fileName
        = QFileDialog::getSaveFileName(this, tr("Save model"));
    if (fileName.isEmpty())
        return;


}

QAction *addAction(QMenu *menu, const QString &text, QActionGroup *group, QSignalMapper *mapper,
                    int id)
{
    bool first = group->actions().isEmpty();
    QAction *result = menu->addAction(text);
    result->setCheckable(true);
    result->setChecked(first);
    group->addAction(result);
    QObject::connect(result, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(result, id);
    return result;
}

void MainWindow::setupDockWidgets(const QMap<QString, QSize> &customSizeHints)
{
    qRegisterMetaType<QDockWidget::DockWidgetFeatures>();

    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(setCorner(int)));

    QMenu *corner_menu = dockWidgetMenu->addMenu(tr("Top left corner"));
    QActionGroup *group = new QActionGroup(this);
    group->setExclusive(true);
    ::addAction(corner_menu, tr("Top dock area"), group, mapper, 0);
    ::addAction(corner_menu, tr("Left dock area"), group, mapper, 1);

    corner_menu = dockWidgetMenu->addMenu(tr("Top right corner"));
    group = new QActionGroup(this);
    group->setExclusive(true);
    ::addAction(corner_menu, tr("Top dock area"), group, mapper, 2);
    ::addAction(corner_menu, tr("Right dock area"), group, mapper, 3);

    corner_menu = dockWidgetMenu->addMenu(tr("Bottom left corner"));
    group = new QActionGroup(this);
    group->setExclusive(true);
    ::addAction(corner_menu, tr("Bottom dock area"), group, mapper, 4);
    ::addAction(corner_menu, tr("Left dock area"), group, mapper, 5);

    corner_menu = dockWidgetMenu->addMenu(tr("Bottom right corner"));
    group = new QActionGroup(this);
    group->setExclusive(true);
    ::addAction(corner_menu, tr("Bottom dock area"), group, mapper, 6);
    ::addAction(corner_menu, tr("Right dock area"), group, mapper, 7);

    dockWidgetMenu->addSeparator();

    static const struct Set {
        const char * name;
        uint flags;
        Qt::DockWidgetArea area;
    } sets [] = {
#ifndef Q_WS_MAC
        { "Black", 0, Qt::LeftDockWidgetArea },
#else
        { "Black", Qt::Drawer, Qt::LeftDockWidgetArea },
#endif
        { "White", 0, Qt::RightDockWidgetArea },
  //      { "Red", 0, Qt::TopDockWidgetArea },
		//{ "Green", 0, Qt::TopDockWidgetArea },
		{ "Yellow", 0, Qt::BottomDockWidgetArea },
        { "Blue", 0, Qt::BottomDockWidgetArea }
    };
    const int setCount = sizeof(sets) / sizeof(Set);

    for (int i = 0; i < setCount; ++i) 
	{
        //ColorSwatch *swatch = new ColorSwatch(tr(sets[i].name), this, Qt::WindowFlags(sets[i].flags));
		ColorSwatch* swatch;
        if (qstrcmp(sets[i].name, "Blue") == 0) 
		{
			swatch = new TextIO(tr(sets[i].name), this, Qt::WindowFlags(sets[i].flags));
            BlueTitleBar *titlebar = new BlueTitleBar(swatch);
            swatch->setTitleBarWidget(titlebar);
            connect(swatch, SIGNAL(topLevelChanged(bool)), titlebar, SLOT(updateMask()));
            connect(swatch, SIGNAL(featuresChanged(QDockWidget::DockWidgetFeatures)), titlebar, SLOT(updateMask()), Qt::QueuedConnection);

#ifdef Q_WS_QWS
            QPalette pal = palette();
            pal.setBrush(backgroundRole(), QColor(0,0,0,0));
            swatch->setPalette(pal);
#endif

        }
		else
			swatch = new ColorSwatch(tr(sets[i].name), this, Qt::WindowFlags(sets[i].flags));

        QString name = QString::fromLatin1(sets[i].name);
        if (customSizeHints.contains(name))
            swatch->setCustomSizeHint(customSizeHints.value(name));

        addDockWidget(sets[i].area, swatch);
        dockWidgetMenu->addMenu(swatch->menu);
    }
}

void MainWindow::setCorner(int id)
{
    switch (id) {
        case 0:
            QMainWindow::setCorner(Qt::TopLeftCorner, Qt::TopDockWidgetArea);
            break;
        case 1:
            QMainWindow::setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
            break;
        case 2:
            QMainWindow::setCorner(Qt::TopRightCorner, Qt::TopDockWidgetArea);
            break;
        case 3:
            QMainWindow::setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
            break;
        case 4:
            QMainWindow::setCorner(Qt::BottomLeftCorner, Qt::BottomDockWidgetArea);
            break;
        case 5:
            QMainWindow::setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
            break;
        case 6:
            QMainWindow::setCorner(Qt::BottomRightCorner, Qt::BottomDockWidgetArea);
            break;
        case 7:
            QMainWindow::setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
            break;
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
}

void MainWindow::switchLayoutDirection()
{
    if (layoutDirection() == Qt::LeftToRight)
        qApp->setLayoutDirection(Qt::RightToLeft);
    else
        qApp->setLayoutDirection(Qt::LeftToRight);
}

// Load model from files
void MainWindow::loadmodel()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Load model"));
	if (fileName.isEmpty())
		return;
	QByteArray ba = fileName.toLatin1();
	std::string fn(ba.data());

	_glWidget->ClearModelNode();
	
	m_pBuildingData->load_3d_data(fn);
	// Set draw geometry
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	geom->setVertexArray(m_pBuildingData->m_3DBuildingVrts.get());
	geom->setColorArray(m_pBuildingData->m_3DBuildingClrs.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE);
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, m_pBuildingData->m_3DBuildingVrts->size()));

	osg::StateSet* sset = geom->getOrCreateStateSet();
	sset->setMode(GL_LIGHTING, osg::StateAttribute::OFF );
	osg::Point* p = new osg::Point;
	p->setSize(4);
	sset->setAttribute(p);

	geode->addDrawable(geom.get());

	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
	osg::Matrix m;
	m.makeRotate(osg::PI/2.0, 1.f, 0.f, 0.f);
	mt->setMatrix(m);
	mt->addChild(geode.get());

	_glWidget->AddModelNode(mt.get());
	_glWidget->ResetCameraPara();
	_glWidget->update();
}