#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T07:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

TARGET = CSE2017
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    background.cpp \
    backgrounds.cpp \
    block.cpp \
    blocks.cpp \
    button.cpp \
    coin_counter.cpp \
    collectable.cpp \
    collectables.cpp \
    collision_master.cpp \
    color_triple_player.cpp \
    counter.cpp \
    enemies.cpp \
    enemy.cpp \
    game_over.cpp \
    level_load.cpp \
    main.cpp \
    menu.cpp \
    music.cpp \
    player.cpp \
    projectile.cpp \
    projectiles.cpp \
    super_powers.cpp \
    test.cpp \
    texture.cpp \
    tools.cpp \
    view.cpp \
    you_win.cpp \
    world.cpp


HEADERS += \
    background.h \
    backgrounds.h \
    base_color_triple.h \
    block.h \
    blocks.h \
    button.h \
    coin_counter.h \
    collectable.h \
    collectables.h \
    collision_master.h \
    color_triple.h \
    color_triple_definition.h \
    color_triple_player.h \
    counter.h \
    enemies.h \
    enemy.h \
    game_over.h \
    global.h \
    level_load.h \
    listheaders.h \
    menu.h \
    music.h \
    player.h \
    projectile.h \
    projectiles.h \
    super_powers.h \
    test.h \
    texture.h \
    tools.h \
    types_states_textures.h \
    view.h \
    you_win.h \
    world.h





# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
