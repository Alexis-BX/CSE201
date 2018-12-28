#ifndef GLOBAL_H
#define GLOBAL_H

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QObject>
#include <QRgb>
#include <QTimer>
#include <QtWidgets>

#include "tools.h"
#include "types_states_textures.h"

class View;

extern View* view;

class Texture;

extern Texture* gtexture;

#endif // GLOBAL_H


/* Libraries that turned out to be useless
#include <QCoreApplication>
#include <QPixmap>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "vector"
#include "cstring"
#include "string"
#include <QDebug>
#include <QtDebug>
#include <QTime>
#include <cstddef>
#include <cstdlib>
#include <iostream>
*/
