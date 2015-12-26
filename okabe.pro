TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    veri/urun.cpp \
    veri/kategori.cpp \
    veri/alis.cpp \
    veri/satis.cpp \
    veri/veritabani.cpp \
    yazilim.cpp \
    arayuz.cpp \
    helper.cpp

HEADERS += \
    veri/urun.h \
    veri/kategori.h \
    veri/alis.h \
    veri/satis.h \
    veri/veritabani.h \
    yazilim.h \
    arayuz.h \
    helper.h

