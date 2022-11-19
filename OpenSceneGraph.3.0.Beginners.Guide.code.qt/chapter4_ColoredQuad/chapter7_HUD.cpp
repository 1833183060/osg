//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter7_HUD.h"
//#include "PickHandler.h"

#include <osg/Camera>

#include <osg/DisplaySettings>
#include <osg/Geode>
#include <osg/Material>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osgDB/WriteFile>
#include <osgDB/ReadFile>
#include <osgGA/EventQueue>
#include <osgGA/TrackballManipulator>

#include <osgUtil/IntersectionVisitor>
#include <osgUtil/PolytopeIntersector>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>
#include <osg/MatrixTransform>
#include <osgUtil/Simplifier>

#include <cassert>

#include <stdexcept>
#include <vector>

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QPen>
#include <QColor>
#include <QDebug>

chapter7_HUD::chapter7_HUD( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
    init();
}

osg::ref_ptr<osg::Node> chapter7_HUD::initSceneData()
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/lz.osg");
        osg::ref_ptr<osg::Node> hud_model = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/glider.osg");
        osg::ref_ptr<osg::Camera> camera = new osg::Camera;
        camera->setClearMask(GL_DEPTH_BUFFER_BIT);
        camera->setRenderOrder(osg::Camera::POST_RENDER);
        camera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
        camera->setViewMatrixAsLookAt(
            osg::Vec3(0.0f, -5.0f, 5.0f), osg::Vec3(),
            osg::Vec3(0.0f, 1.0f, 1.0f)
        );
        camera->addChild(hud_model.get());
        osg::ref_ptr<osg::Group> geode = new osg::Group;
        geode->addChild(model.get());
        geode->addChild( camera.get() );
    return geode;
}

