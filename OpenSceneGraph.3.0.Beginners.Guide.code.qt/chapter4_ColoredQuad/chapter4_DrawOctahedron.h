#ifndef chapter4_DrawOctahedron_h__
#define chapter4_DrawOctahedron_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter4_DrawOctahedron : public osgQWidget
{
  Q_OBJECT

public:
  chapter4_DrawOctahedron( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());

  virtual ~chapter4_DrawOctahedron();



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;
};
#endif
