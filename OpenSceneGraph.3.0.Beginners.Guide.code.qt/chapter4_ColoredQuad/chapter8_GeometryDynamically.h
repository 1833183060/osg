#ifndef chapter8_GeometryDynamically_h__
#define chapter8_GeometryDynamically_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter8_GeometryDynamically : public osgQWidget
{
  Q_OBJECT

public:
  chapter8_GeometryDynamically( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;


  // osgQWidget interface
protected:

};

#endif
