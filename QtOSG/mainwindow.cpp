#include "MainWindow.h"
#include "OSGWidget.h"
#include "osgQOpenGLWidget.h"
#include "osgQOpenGLWindow.h"
#include <QDebug>
#include <QMdiSubWindow>
#include <QMenuBar>

MainWindow::MainWindow( QWidget* parent, Qt::WindowFlags flags )
  : QMainWindow( parent, flags ),
    mdiArea_( new QMdiArea( this ) )
{
  QMenuBar* menuBar = this->menuBar();

  QMenu* menu = menuBar->addMenu( "Test" );
  menu->addAction( "Create view", this, SLOT( onCreateView() ) );
    menu->addAction("Create osgQOpenGLWidget",this,SLOT( onCreate_osgQOpenGLWidget() ));
    menu->addAction("Create osgQOpenGLWindow",this,SLOT( onCreate_osgQOpenGLWindow() ));
  this->setCentralWidget( mdiArea_ );
}

MainWindow::~MainWindow()
{
}

void MainWindow::onCreateView()
{
  OSGWidget* osgWidget     = new OSGWidget( this );
  QMdiSubWindow* subWindow = mdiArea_->addSubWindow( osgWidget );

  subWindow->show();
}

void MainWindow::onCreate_osgQOpenGLWidget()
{
    osgQOpenGLWidget* osgWidget     = new osgQOpenGLWidget( this );
    QMdiSubWindow* subWindow = mdiArea_->addSubWindow( osgWidget );

    subWindow->show();
}

void MainWindow::onCreate_osgQOpenGLWindow()
{
    osgQOpenGLWindow* osgWidget     = new osgQOpenGLWindow( this );
    QMdiSubWindow* subWindow = mdiArea_->addSubWindow(QWidget::createWindowContainer( osgWidget) );

    subWindow->show();
}
