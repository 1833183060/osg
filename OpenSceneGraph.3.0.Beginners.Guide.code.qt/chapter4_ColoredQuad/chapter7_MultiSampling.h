#ifndef chapter7_MultiSampling_h__
#define chapter7_MultiSampling_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter7_MultiSampling : public osgQWidget
{
  Q_OBJECT

public:
  chapter7_MultiSampling( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;


  // osgQWidget interface
protected:

};

#endif
