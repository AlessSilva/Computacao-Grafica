QT += core gui multimedia

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lrt
SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    bib/CurvaCubica.cpp \
    bib/bruxa.cpp \
    bib/morcego.cpp \
    bib/trilho.cpp \
    bib/demonio.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    bib/CurvaCubica.h \
    bib/bruxa.h \
    bib/morcego.h \
    bib/trilho.h \
    bib/demonio.h

