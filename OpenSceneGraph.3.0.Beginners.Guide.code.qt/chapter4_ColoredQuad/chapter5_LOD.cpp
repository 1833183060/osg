//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter5_LOD.h"
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

chapter5_LOD::chapter5_LOD( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
    init();
}

osg::ref_ptr<osg::Node> chapter5_LOD::initSceneData()
{
    osg::ref_ptr<osg::Node> model3 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessna.osg");
        osg::ref_ptr<osg::Node> model2 = dynamic_cast<osg::Node*>(model3->clone(osg::CopyOp::DEEP_COPY_ALL));
        osg::ref_ptr<osg::Node> model1 = dynamic_cast<osg::Node*>(model3->clone(osg::CopyOp::DEEP_COPY_ALL));

        osgUtil::Simplifier simplifier;
        simplifier.setSampleRatio(0.5);
        model2->accept(simplifier);
        simplifier.setSampleRatio(0.1);
        model1->accept(simplifier);

        osg::ref_ptr<osg::LOD> geode = new osg::LOD;
        geode->addChild(model1, 200.0f, FLT_MAX);
        geode->addChild(model2, 50.0f, 200.0);
        geode->addChild(model3, 0.0f, 50.0);
    return geode;
}

