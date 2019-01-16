#ifndef LEVEL_LOAD_H
#define LEVEL_LOAD_H
#include "global.h"
#include "color_triple.h"


class Level_load
{

public:

    Level_load(View* view);

    View* view;

    QGraphicsScene*scene;

    void load_level(QString filename);

    void setup_background();

    void read_level_image(QString filename);

    void color_to_object(int B, int G, int R, pair position);

    std::vector<Base_color_triple*> color_triples;

};

#endif // LEVEL_LOAD_H
