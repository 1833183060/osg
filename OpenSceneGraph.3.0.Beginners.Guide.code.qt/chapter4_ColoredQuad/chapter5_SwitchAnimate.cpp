//修改自 https://github.com/Pseudomanifold/QtOSG

#include "chapter5_SwitchAnimate.h"
//#include "PickHandler.h"

#include <osg/Camera>

#include <osg/DisplaySettings>
#include <osg/Geode>
#include <osg/Material>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osgDB/WriteFile>
#include <osgDB/ReadFile>
#include <osgGA/EventQueue>
#include <osgGA/TrackballManipulator>

#include <osgUtil/IntersectionVisitor>
#include <osgUtil/PolytopeIntersector>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>
#include <osg/MatrixTransform>
#include <osg/Switch>

#include <cassert>

#include <stdexcept>
#include <vector>

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QPen>
#include <QColor>
#include <QDebug>

class AnimatingSwitch : public osg::Switch
{
public:
    AnimatingSwitch() : osg::Switch(), _count(0) {}
    AnimatingSwitch(const AnimatingSwitch& copy, const osg::CopyOp& copyop) :
        osg::Switch(copy, copyop), _count(copy._count) {}

    META_Node(osg, AnimatingSwitch);

    virtual void traverse(osg::NodeVisitor& nv);

protected:
    unsigned int _count;
};

void AnimatingSwitch::traverse(osg::NodeVisitor& nv)
{
    if (!((++_count) % 160))
    {
        setValue(0, !getValue(0));
        setValue(1, !getValue(1));
    }

    osg::Switch::traverse(nv);
}

chapter5_SwitchAnimate::chapter5_SwitchAnimate( QWidget* parent,
                      Qt::WindowFlags f)
  : osgQWidget( parent,f )
{
    init();
}

osg::ref_ptr<osg::Node> chapter5_SwitchAnimate::initSceneData()
{
    osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessna.osg");
        osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile("../../../OpenSceneGraph-Data-master/cessnafire.osg");
        osg::ref_ptr<AnimatingSwitch> geode = new AnimatingSwitch;
        geode->addChild(model1.get(), true);
        geode->addChild(model2.get(), false);
    return geode;
}

