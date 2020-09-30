QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ally.cpp \
    character.cpp \
    charactercreation.cpp \
    city.cpp \
    controls.cpp \
    enemy.cpp \
    fight.cpp \
    fight_handler.cpp \
    forest.cpp \
    guess.cpp \
    hell.cpp \
    items.cpp \
    main.cpp \
    mainwindow.cpp \
    memory.cpp \
    merchant.cpp \
    player.cpp \
    ruins.cpp \
    tavern.cpp \
    text.cpp

HEADERS += \
    ally.h \
    character.h \
    charactercreation.h \
    city.h \
    controls.h \
    enemy.h \
    exceptions.h \
    fight.h \
    fight_handler.h \
    forest.h \
    guess.h \
    hell.h \
    items.h \
    mainwindow.h \
    memory.h \
    merchant.h \
    player.h \
    ruins.h \
    tavern.h \
    text.h

FORMS += \
    City.ui \
    City.ui \
    charactercreation.ui \
    forest.ui \
    guess.ui \
    hell.ui \
    mainwindow.ui \
    memory.ui \
    merchant.ui \
    ruins.ui \
    tavern.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc


FORMS += \
    City.ui \
    charactercreation.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
