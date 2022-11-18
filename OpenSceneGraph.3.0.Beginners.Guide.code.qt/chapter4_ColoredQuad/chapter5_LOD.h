#ifndef chapter5_LOD_h__
#define chapter5_LOD_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter5_LOD : public osgQWidget
{
  Q_OBJECT

public:
  chapter5_LOD( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;


  // osgQWidget interface
protected:

};

#endif
