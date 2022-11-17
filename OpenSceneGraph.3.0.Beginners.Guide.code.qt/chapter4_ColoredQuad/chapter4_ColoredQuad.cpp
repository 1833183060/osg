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

    // Set material for basic lighting and enable depth tests. Else, the sphere
    // will suffer from rendering errors.
   {
      osg::StateSet* stateSet = geode->getOrCreateStateSet();
      osg::Material* material = new osg::Material;

      material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

      stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
      stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );
    }

    float aspectRatio = static_cast<float>( this->width()  ) / static_cast<float>( this->height() );
    auto pixelRatio   = this->devicePixelRatio();

    osg::Camera* camera = new osg::Camera;
    camera->setViewport( 0, 0, this->width()  * pixelRatio, this->height() * pixelRatio );
    camera->setClearColor( osg::Vec4( 0.f, 0.f, 1.f, 1.f ) );
    camera->setProjectionMatrixAsPerspective( 30.f, aspectRatio, 1.f, 1000.f );
    camera->setGraphicsContext( graphicsWindow_ );


    osgGA::TrackballManipulator* manipulator = new osgGA::TrackballManipulator;
    manipulator->setAllowThrow( false );


    viewer_->setCamera(camera);
viewer_->setSceneData( geode.get());
viewer_->setCameraManipulator( manipulator );
    viewer_->setThreadingModel( osgViewer::Viewer::SingleThreaded );
    viewer_->realize();
    // This ensures that the widget will receive keyboard events. This focus
    // policy is not set by default. The default, Qt::NoFocus, will result in
    // keyboard events that are ignored.
    this->setFocusPolicy( Qt::StrongFocus );
    this->setMinimumSize( 100, 100 );

    // Ensures that the widget receives mouse move events even though no
    // mouse button has been pressed. We require this in order to let the
    // graphics window switch viewports properly.
    this->setMouseTracking( true );
}

chapter4_ColoredQuad::~chapter4_ColoredQuad()
{
}


