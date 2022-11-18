#ifndef chapter5_AddModel_h__
#define chapter5_AddModel_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter5_AddModel : public osgQWidget
{
  Q_OBJECT

public:
  chapter5_AddModel( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());

  virtual ~chapter5_AddModel();



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;
};

#endif
