#include "listheaders.h"

Texture::Texture()
{
    read_texture_from_file("Main_texture");

    current_texture2 = "Main_texture";

    read_background_from_file("Main_background");

    current_background2 = "Main_background";
}

void Texture::read_texture_from_file(QString filename)
{
    QFile file(":/Images/Textures/"+filename+'/'+filename+"_list.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QList<QString> temp_list;

    QTextStream in(&file);

    for(int i = 0; i < object_texture_count ; i++)
    {
        temp_list.push_back(in.readLine().split(":")[1].trimmed());
    }

    file.close();

    object_image_from_texure2.insert(filename, temp_list);
}

void Texture::read_background_from_file(QString filename, int amount_close_backgrounds)
{
    QFile file(":/Images/Backgrounds/"+filename+'/'+filename+"_list.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QList<QString> temp_list_1;

    QTextStream in(&file);

    for(int i = 0; i < background_texture_count - 1 ; i++)
    {
        temp_list_1.push_back(in.readLine().split(":")[1].trimmed());
    }


    QList<QString> temp_list_close;

    for(int i = 0; i < amount_close_backgrounds ; i++)
    {
        temp_list_close.push_back(in.readLine().split(":")[1].trimmed());
    }

    file.close();

    background_image_from_background2.insert(filename, temp_list_1);

    background_image_from_background_close2.insert(filename, temp_list_close);

}

QString Texture::get_path_to(Object_texture ojb_tex)
{
    return path_to_textures2+current_texture2+'/'+object_image_from_texure2.find(current_texture2).value()[ojb_tex]+".png";
}

QString Texture::get_path_to(Background_texture bg_tex)
{
    if (bg_tex == background_close)
    {
        int pos = (std::time(nullptr))%background_image_from_background_close2.find(current_background2).value().size();
        return path_to_backgrounds2+current_background2+'/'+background_image_from_background_close2.find(current_background2).value()[pos]+".png";
    }
    return path_to_backgrounds2+current_background2+'/'+background_image_from_background2.find(current_background2).value()[bg_tex]+".png";
}

std::vector<QPixmap> Texture::get_qpixmap_of(Object_texture sheet, int start, int length, int size)
{
    QPixmap img(get_path_to(sheet));

    int w = img.width()/size;

    int i = start%w, j = start/w;

    std::vector<QPixmap> res(length);

    for (int k=0; k<length; k++)
    {
        res[k] = img.copy(((i+k)%w)*size, (j+(i+k)/w)*size, size, size);
    }

    return res;
}
