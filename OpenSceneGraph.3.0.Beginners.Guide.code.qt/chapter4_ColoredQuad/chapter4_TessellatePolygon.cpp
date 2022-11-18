//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter4_TessellatePolygon.h"
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

chapter4_TessellatePolygon::chapter4_TessellatePolygon( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
   init();
}

chapter4_TessellatePolygon::~chapter4_TessellatePolygon()
{
}

osg::ref_ptr<osg::Node> chapter4_TessellatePolygon::initSceneData()
{
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
        vertices->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
        vertices->push_back(osg::Vec3(2.0f, 0.0f, 0.0f));
        vertices->push_back(osg::Vec3(2.0f, 0.0f, 1.0f));
        vertices->push_back(osg::Vec3(1.0f, 0.0f, 1.0f));
        vertices->push_back(osg::Vec3(1.0f, 0.0f, 2.0f));
        vertices->push_back(osg::Vec3(2.0f, 0.0f, 2.0f));
        vertices->push_back(osg::Vec3(2.0f, 0.0f, 3.0f));
        vertices->push_back(osg::Vec3(0.0f, 0.0f, 3.0f));
        osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
        normals->push_back(osg::Vec3(0.0f, -1.0f, 0.0f));

        osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
        geom->setVertexArray(vertices);
        geom->setNormalArray(normals);
        geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
        geom->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON, 0, 8));

        osgUtil::Tessellator tessellator;
        tessellator.retessellatePolygons(*geom);

        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
        geode->addDrawable(geom.get());

return geode;
}
