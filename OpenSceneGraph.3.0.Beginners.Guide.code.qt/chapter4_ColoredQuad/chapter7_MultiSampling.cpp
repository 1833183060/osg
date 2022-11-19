//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter7_MultiSampling.h"
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

chapter7_MultiSampling::chapter7_MultiSampling( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
    init();
}

osg::ref_ptr<osg::Node> chapter7_MultiSampling::initSceneData()
{
    osg::DisplaySettings::instance()->setNumMultiSamples(4);
        osg::ref_ptr<osg::Node> geode = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessna.osg");
    return geode;
}

