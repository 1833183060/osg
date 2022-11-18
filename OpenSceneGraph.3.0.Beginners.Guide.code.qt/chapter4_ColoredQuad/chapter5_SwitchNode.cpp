//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter5_SwitchNode.h"
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

chapter5_SwitchNode::chapter5_SwitchNode( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
    init();
}

osg::ref_ptr<osg::Node> chapter5_SwitchNode::initSceneData()
{
    osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessna.osg");
        osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessnafire.osg");
        osg::ref_ptr<osg::Switch> geode = new osg::Switch;
        geode->addChild(model1, false);
        geode->addChild(model2, true);

    return geode;
}

