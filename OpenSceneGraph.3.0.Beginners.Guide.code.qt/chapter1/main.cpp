
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
int main(int argc, char *argv[])
{
    osgViewer::Viewer viewer;
    viewer.setSceneData(osgDB::readNodeFile("E:/mywork/osg/OpenSceneGraph-Data-master/cessna.osg"));
    return viewer.run();


}
