#include "listheaders.h"

Collision_master::Collision_master()
{
    read_rules_from_file("Player");
}

void Collision_master::read_rules_from_file(QString name)
{
    QFile file(":/Images/Rules/Collisions.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(nullptr, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    QString buffer_string;

    do
    {
        buffer_string = in.readLine().trimmed();
        qDebug() << buffer_string;

    } while (buffer_string != "#"+name);
    in.readLine();

    QList<QString> buffer_list;

    while(true)
    {
        buffer_list = in.readLine().split(':');
        if(buffer_list.size() == 1)
        {
            break;
        }
        buffer_list[0] = buffer_list[0].trimmed();
        buffer_list[0].prepend(QString::number(buffer_list[0].size()));
        rules.insert(buffer_list[0],buffer_list[1].trimmed());
        qDebug() << buffer_list[0] << buffer_list[1].trimmed();
    }

    file.close();
}

QString Collision_master::collide(QString colliding_with)
{
    if( rules.find(colliding_with) == rules.end())
    {
        return "nothing";
    }
    return rules.find(colliding_with).value();
}

