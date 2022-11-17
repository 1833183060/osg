#include "MainWindow.h"
#include "chapter4_ColoredQuad.h"
#include "chapter4_DrawOctahedron.h"
#include "chapter4_TessellatePolygon.h"
#include "chapter4_PrimitiveFunctor.h"
#include <QDebug>
#include <QMdiSubWindow>
#include <QMenuBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow( QWidget* parent, Qt::WindowFlags flags )
  : QMainWindow( parent, flags ),
    mdiArea_( new QMdiArea( this ) )
{
  QMenuBar* menuBar = this->menuBar();

  QMenu* menu = menuBar->addMenu( "Test" );
  menu->addAction( "chapter4_ColoredQuad", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter4_ColoredQuad( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter4_DrawOctahedron", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter4_DrawOctahedron( this ) );
      subWindow->show();
  });
  menu->addAction( "chapter4_TessellatePolygon", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter4_TessellatePolygon( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter4_PrimitiveFunctor", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter4_PrimitiveFunctor( this ) );
      subWindow->show();
  });
  //chapter4_TessellatePolygon

  this->setCentralWidget( mdiArea_ );


}

MainWindow::~MainWindow()
{
}

void MainWindow::onCreateView(QString name)
{
  chapter4_ColoredQuad* osgWidget     = new chapter4_ColoredQuad( this );
  QMdiSubWindow* subWindow = mdiArea_->addSubWindow( osgWidget );

  subWindow->show();
}


