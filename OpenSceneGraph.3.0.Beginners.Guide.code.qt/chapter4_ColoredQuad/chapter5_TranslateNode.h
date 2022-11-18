#ifndef chapter5_TranslateNode_h__
#define chapter5_TranslateNode_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter5_TranslateNode : public osgQWidget
{
  Q_OBJECT

public:
  chapter5_TranslateNode( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());

  virtual ~chapter5_TranslateNode();



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;


  // osgQWidget interface
protected:

};

#endif
