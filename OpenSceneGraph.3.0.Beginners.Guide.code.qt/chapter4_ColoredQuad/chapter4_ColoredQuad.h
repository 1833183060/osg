#ifndef chapter4_ColoredQuad_h__
#define chapter4_ColoredQuad_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter4_ColoredQuad : public osgQWidget
{
  Q_OBJECT

public:
  chapter4_ColoredQuad( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());

  virtual ~chapter4_ColoredQuad();

protected:



private:


};

#endif
