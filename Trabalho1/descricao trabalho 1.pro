TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/objeto.cpp \
    pessoal/cactus.cpp \
    pessoal/camel.cpp \
    pessoal/pyramid.cpp \
    pessoal/skull.cpp \
    pessoal/tree.cpp \
    pessoal/mummy.cpp \
    pessoal/sun.cpp \
    pessoal/esfinge.cpp \
    pessoal/farao.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/objeto.h \
    pessoal/cactus.h \
    pessoal/camel.h \
    pessoal/pyramid.h \
    pessoal/skull.h \
    pessoal/tree.h \
    pessoal/mummy.h \
    pessoal/sun.h \
    pessoal/esfinge.h \
    pessoal/farao.h
