QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomba.cpp \
    brokenblock.cpp \
    explotion.cpp \
    field.cpp \
    hardblock.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    score.cpp

HEADERS += \
    block.h \
    bomba.h \
    brokenblock.h \
    confi.h \
    explotion.h \
    field.h \
    hardblock.h \
    mainwindow.h \
    player.h \
    score.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    graficos.qrc
