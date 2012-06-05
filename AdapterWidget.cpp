/* OpenSceneGraph example, osganimate.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*  THE SOFTWARE.
*/

#include "AdapterWidget.h"

AdapterWidget::AdapterWidget( QWidget * parent, const char * name, const QGLWidget * shareWidget, WindowFlags f):
    QGLWidget(parent, shareWidget, f)
{
    _gw = new osgViewer::GraphicsWindowEmbedded(0,0,width(),height());
    setFocusPolicy(Qt::ClickFocus);
}

void AdapterWidget::init()
{

}

void AdapterWidget::resizeGL( int width, int height )
{
    _gw->getEventQueue()->windowResize(0, 0, width, height );
    _gw->resized(0,0,width,height);
}

void AdapterWidget::keyPressEvent( QKeyEvent* event )
{
    _gw->getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toAscii().data() ) );

}

void AdapterWidget::keyReleaseEvent( QKeyEvent* event )
{
    _gw->getEventQueue()->keyRelease( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toAscii().data() ) );
}

void AdapterWidget::mousePressEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
}

void AdapterWidget::mouseReleaseEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
}

void AdapterWidget::mouseMoveEvent( QMouseEvent* event )
{
    _gw->getEventQueue()->mouseMotion(event->x(), event->y());
}

//////////////////////////////////////////////////////////////////////////
//
ViewerQT::ViewerQT(QWidget * parent, const char * name, const QGLWidget * shareWidget, WindowFlags f):
	AdapterWidget( parent, name, shareWidget, f)
{
	// Camera
	getCamera()->setViewport(new osg::Viewport(0,0,width(),height()));
	getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(width())/static_cast<double>(height()), 1.0f, 10000.0f);
	getCamera()->setGraphicsContext(getGraphicsWindow());
	getCamera()->setClearColor(osg::Vec4d(51/255.0, 51/255.0, 102/255.0, 0));
	//getCamera()->setClearColor(osg::Vec4d(1, 1, 1, 0));

	// Trackball
	m_rpTrackball = new osgGA::TrackballManipulator;
	setCameraManipulator(m_rpTrackball.get());

	// Scene root
	m_rpSceneGroupRoot = new osg::Group;
	setSceneData(m_rpSceneGroupRoot.get());

	//
	setThreadingModel(osgViewer::Viewer::SingleThreaded);

	connect(&_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	_timer.start(10);
}

// Reset pespective by bounding nodes
void ViewerQT::ResetCameraPara()
{
	if (m_rpSceneGroupRoot->getNumChildren()==0)
		return;
	osg::BoundingSphere vSphere = m_rpSceneGroupRoot->computeBound();
	setCameraManipulator(m_rpTrackball.get());
	((osgGA::TrackballManipulator*)getCameraManipulator())->setCenter(vSphere.center());
	((osgGA::TrackballManipulator*)getCameraManipulator())->setDistance(vSphere.radius()*2.5);
}

// Add model to scene
void ViewerQT::AddModelNode(osg::ref_ptr<osg::Node> mnode)
{
	m_rpSceneGroupRoot->addChild(mnode.get());
}

// Clear model from scene
void ViewerQT::ClearModelNode()
{
	m_rpSceneGroupRoot->removeChildren(0, m_rpSceneGroupRoot->getNumChildren());
}