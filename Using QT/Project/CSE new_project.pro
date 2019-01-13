#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T07:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
        main.cpp \
    test.cpp \
    player.cpp \
    block.cpp \
    view.cpp \
    projectile.cpp \
    collectable.cpp \
    coin_counter.cpp \
    counter.cpp \
    enemy.cpp \
    texture.cpp \
    blocks.cpp \
    projectiles.cpp \
    tools.cpp \
    level_load.cpp \
    collectables.cpp \
    background.cpp \
    backgrounds.cpp \
    enemies.cpp \
    base_color_triple.cpp \
    color_triple_player.cpp \
    collision_master.cpp \
    game_over.cpp \
    super_powers.cpp \
    menu.cpp \
    button.cpp \
    music.cpp \
    enemies.cpp


HEADERS += \
    test.h \
    player.h \
    block.h \
    view.h \
    projectile.h \
    collectable.h \
    types_states_textures.h \
    tools.h \
    coin_counter.h \
    counter.h \
    enemy.h \
    texture.h \
    global.h \
    blocks.h \
    projectiles.h \
    level_load.h \
    collectables.h \
    background.h \
    backgrounds.h \
    listheaders.h \
    enemies.h \
    color_triple.h \
    color_triple_definition.h \
    base_color_triple.h \
    color_triple_player.h \
    start_screen.h \
    collision_master.h \
    game_over.h \
    super_powers.h \
    menu.h \
    button.h \
    music.h \
    enemies.h





# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
