#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include <QMainWindow>
#include <QObject>
#include <QRgb>
#include <QSound>
#include <QTimer>
#include <QUrl>
#include <QtWidgets>
#include <QWidget>

#include "tools.h"
#include "types_states_textures.h"

class View;

extern View* view;

class Texture;

extern Texture* gtexture;

class Collision_master;

extern Collision_master* collision_master;

#endif // GLOBAL_H
