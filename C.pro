######################################################################
# Automatically generated by qmake (3.0) ? 2? 13 17:45:19 2016
######################################################################

QT += concurrent widgets
QT += sql
QT += widgets

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

# Input
HEADERS += InteractionServer.h \
           extract_html.h \
           import_internet.h \
           multi_concurrent.h \
           multi_threading.h
SOURCES += InteractionServer.cpp \
           extract_html.cpp \
           import_internet.cpp \
           main.cpp \
           multi_concurrent.cpp \
           multi_threading.cpp

release: DESTDIR = /home/roveref/Software/build/release
debug:   DESTDIR = /home/roveref/Software/build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui