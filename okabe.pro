TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    veri/urun.cpp \
    veri/kategori.cpp \
    veri/alis.cpp \
    veri/satis.cpp \
    veri/veritabani.cpp \
    src/yazilim.cpp \
    src/arayuz.cpp

HEADERS += \
    veri/urun.h \
    veri/kategori.h \
    veri/alis.h \
    veri/satis.h \
    veri/veritabani.h \
    src/yazilim.h \
    src/arayuz.h

