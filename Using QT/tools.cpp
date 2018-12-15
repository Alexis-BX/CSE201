#include "tools.h"
#include "cstring"
#define pixmap_dir ":/images/main_texture_pack/"

const char* add_dir(const char* image)
{
    const unsigned int length = strlen(pixmap_dir) + strlen(image) + 1;

    char* pixmap = new char[length];

    strcpy(pixmap,pixmap_dir);

    strcat(pixmap,image);

    return pixmap;
};

