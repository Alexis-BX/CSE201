#ifndef COLLISION_MASTER_H
#define COLLISION_MASTER_H
#include "global.h"


class Collision_master
{

public:

    Collision_master();

    void read_rules_from_file(QString name);

    QString collide(QString colliding_with);

    QMap<QString,QString> rules;
};


#endif // COLLISION_MASTER_H
