cmake_minimum_required(VERSION 3.5)

project(projectdemo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projectdemo
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}


        areaa.h areaa.cpp areaa.ui
        areab.h areab.cpp areab.ui
        areac.h areac.cpp areac.ui
        aread.h aread.cpp aread.ui
        a.qrc
        b.qrc
        c.qrc
        d.qrc
        map.qrc
        page2.h page2.cpp page2.ui
        page1.h page1.cpp page1.ui
        tip.h tip.cpp tip.ui
        page3.h page3.cpp page3.ui
        widget.h widget.cpp widget.ui
        customdic.cpp customdic.h customdic.ui
        widget_.h widget_.cpp widget_.ui

        page4.h page4.cpp page4.ui
        material.qrc
        tip_.h tip_.cpp tip_.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET projectdemo APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(projectdemo SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(projectdemo
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(projectdemo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.projectdemo)
endif()
set_target_properties(projectdemo PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS projectdemo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projectdemo)
endif()
