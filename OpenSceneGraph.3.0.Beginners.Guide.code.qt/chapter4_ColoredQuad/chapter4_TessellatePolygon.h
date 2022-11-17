#ifndef chapter4_TessellatePolygon_h__
#define chapter4_TessellatePolygon_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter4_TessellatePolygon : public osgQWidget
{
  Q_OBJECT

public:
  chapter4_TessellatePolygon( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());

  virtual ~chapter4_TessellatePolygon();


};

#endif
