#pragma once

#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>


#include <QtCore/QString>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>
#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiSubWindow>
#include <QtGui/QMdiArea>

using Qt::WindowFlags;


#include <iostream>

class AdapterWidget : public QGLWidget
{
public:

	AdapterWidget( QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WindowFlags f = 0 );

	virtual ~AdapterWidget() {}

	osgViewer::GraphicsWindow* getGraphicsWindow() { return _gw.get(); }
	const osgViewer::GraphicsWindow* getGraphicsWindow() const { return _gw.get(); }

protected:

	void init();

	virtual void resizeGL( int width, int height );
	virtual void keyPressEvent( QKeyEvent* event );
	virtual void keyReleaseEvent( QKeyEvent* event );
	virtual void mousePressEvent( QMouseEvent* event );
	virtual void mouseReleaseEvent( QMouseEvent* event );
	virtual void mouseMoveEvent( QMouseEvent* event );

	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _gw;
};



class ViewerQT : public osgViewer::Viewer, public AdapterWidget
{
public:

	ViewerQT(QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WindowFlags f = 0);
	virtual void paintGL()
	{
		frame();
	}

public:
	void ResetCameraPara();
	void AddModelNode(osg::ref_ptr<osg::Node> mnode);
	void ClearModelNode();

public:
	osg::ref_ptr<osgGA::TrackballManipulator>	m_rpTrackball;
	osg::ref_ptr<osg::Group>	m_rpSceneGroupRoot;

protected:

	QTimer _timer;
};

