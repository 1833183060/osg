#ifndef chapter5_SwitchNode_h__
#define chapter5_SwitchNode_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include "osgQWidget.h"


class chapter5_SwitchNode : public osgQWidget
{
  Q_OBJECT

public:
  chapter5_SwitchNode( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());



  // osgQWidget interface
protected:
  osg::ref_ptr<osg::Node> initSceneData() override;


  // osgQWidget interface
protected:

};

#endif
