#ifndef COLLECTABLE_H
#define COLLECTABLE_H 

#include <QGraphicsPixmapItem>
#include <QObject>

struct pair
{
    int x,y ;
};

class Screen;

extern Screen* screen;

enum Collectable_state  // the collectable can either be used by the player or not
{
    used,
    unused
};

enum Collectable_type // shows all kinds of collectables that can appear
{
    star,
    mushroom,
    eclair
};

enum Collectable_texture  // shows if the player meets the same or different collectable
{
    same,
    different
};

class Collectable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    Collectable_type type;             // shows the kind of collectable the player meets
    Collectable_state state;           // shows if the collectable is used or unused
    Collectable_texture texture;       // the player meets the same or different collectable

public:

    pair size;

    Collectable(pair position, pair size, Collectable_type type, Collectable_state state, Collectable_texture texture, QGraphicsItem* parent = 0 );

    void Set_State(Collectable_state state);

    Collectable_state Get_State() const;

    void Set_Type(Collectable_type type);

    Collectable_type Get_Type() const;

    void Set_Texture(Collectable_texture texture);

    Collectable_texture Get_Texture() const;

};

#endif // COLLECTABLE_H
