//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter4_DrawOctahedron.h"
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

#include <cassert>

#include <stdexcept>
#include <vector>

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QPen>
#include <QColor>

chapter4_DrawOctahedron::chapter4_DrawOctahedron( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )

{
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(6);
        (*vertices)[0].set(0.0f, 0.0f, 1.0f);
        (*vertices)[1].set(-0.5f, -0.5f, 0.0f);
        (*vertices)[2].set( 0.5f, -0.5f, 0.0f);
        (*vertices)[3].set(0.5f, 0.5f, 0.0f);
        (*vertices)[4].set(-0.5f, 0.5f, 0.0f);
        (*vertices)[5].set(0.0f, 0.0f, -1.0f);

        osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_TRIANGLES, 24);
        (*indices)[0] = 0;
        (*indices)[1] = 1;
        (*indices)[2] = 2;
        (*indices)[3] = 0;
        (*indices)[4] = 2;
        (*indices)[5] = 3;
        (*indices)[6] = 0;
        (*indices)[7] = 3;
        (*indices)[8] = 4;
        (*indices)[9] = 0;
        (*indices)[10] = 4;
        (*indices)[11] = 1;
        (*indices)[12] = 5;
        (*indices)[13] = 2;
        (*indices)[14] = 1;
        (*indices)[15] = 5;
        (*indices)[16] = 3;
        (*indices)[17] = 2;
        (*indices)[18] = 5;
        (*indices)[19] = 4;
        (*indices)[20] = 3;
        (*indices)[21] = 5;
        (*indices)[22] = 1;
        (*indices)[23] = 4;

        osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
        geom->setVertexArray(vertices.get());
        geom->addPrimitiveSet(indices.get());
        osgUtil::SmoothingVisitor::smooth(*geom);

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

chapter4_DrawOctahedron::~chapter4_DrawOctahedron()
{
}
