#include "MainWindow.h"
#include "chapter4_ColoredQuad.h"
#include "chapter4_DrawOctahedron.h"
#include "chapter4_TessellatePolygon.h"
#include "chapter4_PrimitiveFunctor.h"
#include "chapter5_AddModel.h"
#include "chapter5_TranslateNode.h"
#include "chapter5_SwitchNode.h"
#include "chapter5_LOD.h"
#include "chapter5_SwitchAnimate.h"
#include "chapter7_HUD.h"
#include "chapter7_MultiSampling.h"
#include "chapter8_GeometryDynamically.h"
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

  menu->addAction( "chapter5_AddModel", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter5_AddModel( this ) );
      subWindow->show();
  });
  menu->addAction( "chapter5_TranslateNode", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter5_TranslateNode( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter5_SwitchNode", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter5_SwitchNode( this ) );
      subWindow->show();
  });
  menu->addAction( "chapter5_LOD", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter5_LOD( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter5_SwitchAnimate", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter5_SwitchAnimate( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter7_HUD", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter7_HUD( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter7_MultiSampling", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter7_MultiSampling( this ) );
      subWindow->show();
  });

  menu->addAction( "chapter8_GeometryDynamically", this, [=](){
      QMdiSubWindow* subWindow = mdiArea_->addSubWindow( new chapter8_GeometryDynamically( this ) );
      subWindow->show();
  });
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


