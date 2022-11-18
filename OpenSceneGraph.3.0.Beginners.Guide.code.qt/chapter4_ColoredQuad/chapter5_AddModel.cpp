//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter5_AddModel.h"
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
#include <osgUtil/Tessellator>

#include <cassert>

#include <stdexcept>
#include <vector>

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QPen>
#include <QColor>

chapter5_AddModel::chapter5_AddModel( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
init();
}

chapter5_AddModel::~chapter5_AddModel()
{
}

osg::ref_ptr<osg::Node> chapter5_AddModel::initSceneData()
{
    osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessna.osg");
        osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cow.osg");
        osg::ref_ptr<osg::Group> geode = new osg::Group;
        geode->addChild(model1.get());
        geode->addChild(model2.get());
        //geode->addDrawable(geom.get());
return geode;
}
