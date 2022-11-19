#ifndef osgQWidget_h__
#define osgQWidget_h__

#include <QPoint>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <osg/ref_ptr>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
#include <QTimer>


class osgQWidget : public QOpenGLWidget
{
  Q_OBJECT

public:
  osgQWidget( QWidget* parent = 0,Qt::WindowFlags f = Qt::WindowFlags());

  virtual ~osgQWidget();

protected:

  //virtual void paintEvent( QPaintEvent* paintEvent );
  virtual void paintGL();
  virtual void resizeGL( int width, int height );

  virtual void keyPressEvent( QKeyEvent* event );
  virtual void keyReleaseEvent( QKeyEvent* event );

  virtual void mouseMoveEvent( QMouseEvent* event );
  virtual void mousePressEvent( QMouseEvent* event );
  virtual void mouseReleaseEvent( QMouseEvent* event );
  virtual void wheelEvent( QWheelEvent* event );

  virtual bool event( QEvent* event );

  virtual osg::ref_ptr<osg::Node> initSceneData(){return nullptr;};

  void initSet();
  void init();
protected:

  virtual void onHome();
  virtual void onResize( int width, int height );

  osgGA::EventQueue* getEventQueue() const;

  osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphicsWindow_;
  osg::ref_ptr<osgViewer::Viewer> viewer_;
    osg::ref_ptr<osg::Node> root;
QTimer* timer;
    // QOpenGLWidget interface
protected:
    void initializeGL() override;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event) override;
};

#endif
