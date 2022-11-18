//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter5_TranslateNode.h"
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

chapter5_TranslateNode::chapter5_TranslateNode( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
    init();
}

chapter5_TranslateNode::~chapter5_TranslateNode()
{
}

osg::ref_ptr<osg::Node> chapter5_TranslateNode::initSceneData()
{
    qDebug()<<"chapter5_TranslateNode::initSceneData";
    osg::ref_ptr<osg::Group> geode = new osg::Group;
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessna.osg");
    osg::ref_ptr<osg::MatrixTransform> transformation1 = new osg::MatrixTransform;
    transformation1->setMatrix(osg::Matrix::translate(-25.0f, 0.0f, 0.0f));
    transformation1->addChild(model.get());
    osg::ref_ptr<osg::MatrixTransform> transformation2 = new osg::MatrixTransform;
    transformation2->setMatrix(osg::Matrix::translate(25.0f, 0.0f, 0.0f));
    transformation2->addChild(model.get());


    geode->addChild(transformation1.get());
    geode->addChild(transformation2.get());

    return geode;
}

