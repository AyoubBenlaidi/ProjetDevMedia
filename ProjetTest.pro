

QT += core gui
QT += opengl
QT += core gui opengl
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



TARGET = Projet
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    scenedejeu.cpp \
    partie.cpp \
    cible.cpp \
    terrain.cpp \
    projectile.cpp

HEADERS  += mainwindow.h \
    scenedejeu.h \
    partie.h \
    cible.h \
    terrain.h \
    projectile.h

FORMS    += mainwindow.ui


INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_videoio \
    -lopencv_features2d \
    -lopencv_calib3d \
    -lglut \
    -lGLU

RESOURCES += \
    ima.qrc

DISTFILES +=
