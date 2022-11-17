cmake_minimum_required(VERSION 3.5)

project(QtOSG VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools opengl OpenGLWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools  opengl OpenGLWidgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        OSGWidget.h
        OSGWidget.cpp
        osgQOpenGLWidget.h
        osgQOpenGLWidget.cpp
        osgQOpenGLWindow.h
        osgQOpenGLWindow.cpp
        OSGRenderer.h
        OSGRenderer.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtOSG
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtOSG APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(QtOSG SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtOSG
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()
link_libraries("E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib")
target_link_libraries(QtOSG PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets Qt${QT_VERSION_MAJOR}::OpenGL opengl32 GLU32
    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/osgd.lib"
    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/osgDBd.lib"
    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/osgGAd.lib"
    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/osgViewerd.lib"

    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/OpenThreadsd.lib"
    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/osgUtild.lib"
    "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/lib/osgViewerd.lib"
)

set_target_properties(QtOSG PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtOSG)
endif()

include_directories("E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/include" "E:/download/OpenSceneGraph-OpenSceneGraph-3.6.5/build/include")
