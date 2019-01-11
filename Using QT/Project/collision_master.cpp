#include "listheaders.h"

Collision_master::Collision_master()
{
    read_rules_from_file();
}

void Collision_master::read_rules_from_file()
{
    QFile file(":/Images/Rules/Collisions.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(nullptr, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    QString buffer_string, name;

    QList<QString> buffer_list;

    QMap<QString,QString> buffer_map;

    for(int i = 0 ; i < 4 ; i ++)
    {
        do
        {
            buffer_string = in.readLine().trimmed();
            if(buffer_string.isNull())
            {
                return;
            }
            else
            {
                qDebug() << buffer_string[0];
            }
        } while (buffer_string[0] != "#");

        name = buffer_string.trimmed();

        in.readLine();

        while(true)
        {
            buffer_list = in.readLine().split(':');
            if(buffer_list.size() != 2)
            {
                break;
            }
            buffer_list[0] = buffer_list[0].trimmed();
            buffer_list[0].prepend(QString::number(buffer_list[0].size()));
            buffer_map.insert(buffer_list[0],buffer_list[1].trimmed());
        }

        rules.insert(name,buffer_map);
    }

    file.close();
}

QString Collision_master::collide(QString name, QString colliding_with)
{
    name.prepend("#");
    if( rules.find(name) == rules.end())
    {
        return "nothing";
    }
    if( rules.find(name).value().find(colliding_with) == rules.find(name).value().end())
    {
        return "nothing";
    }
    return rules.find(name).value().find(colliding_with).value();
}

