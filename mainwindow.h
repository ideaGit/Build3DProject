/****************************************************************************
**
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QScrollArea>
#include <QGridLayout>
#include "AdapterWidget.h"

class ToolBar;
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(QSignalMapper)

class CBuildingData;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTextEdit *center;
    QList<ToolBar*> toolBars;
    QMenu *dockWidgetMenu;
    QMenu *mainWindowMenu;
    QSignalMapper *mapper;
    QList<QDockWidget*> extraDockWidgets;

public:
    MainWindow(const QMap<QString, QSize> &customSizeHints,
                QWidget *parent = 0, Qt::WindowFlags flags = 0);

protected:
    void showEvent(QShowEvent *event);

public slots:
    void actionTriggered(QAction *action);
    void savemodel();
    void loadmodel();
    void setCorner(int id);
    void switchLayoutDirection();
    void setDockOptions();

	//open pictures
	void openFiles();
	void deleteThread();
	void showError(const QString filename);
	void addThumbnail(QImage);
public:

public:
	ViewerQT*	_glWidget;

	CBuildingData *		m_pBuildingData;

private:
    void setupToolBar();
    void setupMenuBar();
    void setupDockWidgets(const QMap<QString, QSize> &customSizeHints);

	void createThumbnail(const QString& filename);
	QWidget* previewwidget;
	QWidget * main;
	QScrollArea * pScroll;
	QGridLayout* picGird;
	int waitseconds;
};


#endif
