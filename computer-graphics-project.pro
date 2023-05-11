QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clipping.cpp \
    genericobject.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    pentagon.cpp \
    point.cpp \
    rectangle.cpp \
    triangle.cpp \
    window.cpp

HEADERS += \
    clipping.h \
    genericobject.h \
    line.h \
    mainwindow.h \
    matrix.h \
    pentagon.h \
    point.h \
    rectangle.h \
    triangle.h \
    window.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
