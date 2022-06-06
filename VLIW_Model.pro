QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    core/comand.cpp \
    core/instruction.cpp \
    core/proccessor.cpp \
    core/register.cpp \
    core/registerblock.cpp \
    main.cpp \
    parser.cpp \
    view/codeeditor.cpp \
    view/mainwindow.cpp \
    view/memorymainwindow.cpp \
    view/pipelineitem.cpp \
    view/registermainform.cpp \
    view/windowmanager.cpp \
    view/workwindow.cpp

HEADERS += \
    controller.h \
    core/KeyWords.h \
    core/comand.h \
    core/core.h \
    core/instruction.h \
    core/proccessor.h \
    core/register.h \
    core/registerblock.h \
    parser.h \
    view/codeeditor.h \
    view/gui.h \
    view/linenumberarea.h \
    view/mainwindow.h \
    view/memorymainwindow.h \
    view/pipelineitem.h \
    view/registermainform.h \
    view/windowmanager.h \
    view/workwindow.h

FORMS += \
    view/mainwindow.ui \
    view/memorymainwindow.ui \
    view/registermainform.ui \
    view/workwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc

