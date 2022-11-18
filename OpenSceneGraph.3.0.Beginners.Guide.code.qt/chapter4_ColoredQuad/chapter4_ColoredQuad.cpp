//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter4_ColoredQuad.h"
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

#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>

#include <cassert>

#include <stdexcept>
#include <vector>

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QPen>
#include <QColor>

chapter4_ColoredQuad::chapter4_ColoredQuad( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{  
    init();
}

chapter4_ColoredQuad::~chapter4_ColoredQuad()
{
}

osg::ref_ptr<osg::Node> chapter4_ColoredQuad::initSceneData()
{
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
        osg::ref_ptr<osg::Vec3Array> verts = new osg::Vec3Array;
        verts->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
        verts->push_back(osg::Vec3(1.0f, 0.0f, 0.0f));
        verts->push_back(osg::Vec3(1.0f, 0.0f, 1.0f));
        verts->push_back(osg::Vec3(0.0f, 0.0f, 1.0f));
        osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
        normals->push_back(osg::Vec3(0.0f, -1.0f, 0.0f));
        osg::ref_ptr<osg::Vec3Array> colors = new osg::Vec3Array;
        colors->push_back(osg::Vec3(1.0f, 0.0f, 0.0f));
        colors->push_back(osg::Vec3(0.0f, 1.0f, 0.0f));
        colors->push_back(osg::Vec3(0.0f, 0.0f, 1.0f));
        colors->push_back(osg::Vec3(1.0f, 1.0f, 1.0f));
        geom->setVertexArray(verts.get());
        geom->setNormalArray(normals.get());
        geom->setColorArray(colors.get());
        geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
        geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

        geom->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));

        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
        geode->addDrawable(geom.get());
        return geode;
}


