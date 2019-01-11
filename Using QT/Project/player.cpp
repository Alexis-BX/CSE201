#include "listheaders.h"

Player::Player(QGraphicsItem* parent) :
    QObject(), QGraphicsPixmapItem (parent)
{
    create_animation();

    collision_ranges = create_collision_range<Player>(this);

    this->setZValue(layer_player);

    // Timer
    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(view->ms_between_updates);
}

/**NOTE:
 *  FOR THE moment i made it so the player chooses the items he throws just for testing collisions
 * the designs i made are shit and i know it but again its just to test
 *
 * - adrien
 * **/

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
    {
        pressed_left = true;
        break;
    }
    case Qt::Key_Right:
    {
        pressed_right = true;
        break;
    }
    case Qt::Key_Up:
    {
        jump();
        break;
    }
    case Qt::Key_Space:
    {
        throw_projectile();
        break;
    }
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
    {
        pressed_left = false;
        break;
    }
    case Qt::Key_Right:
    {
        pressed_right = false;
        break;
    }
    }
}

void Player::move()
{
    //Accelerate
    speed.y += 1;

    //Motion smooth
    if (pressed_left)
    {
        if (speed.x>-max_speed.x)
        {
            speed.x -= 1;
        }
    }
    else
    {
        if (speed.x<0)
        {
            speed.x = (speed.x < -1) ? speed.x/2 : 0;
        }
    }

    if (pressed_right)
    {
        if (speed.x<max_speed.x*((super_fast) ? 2 : 1))
        {
            speed.x += 1;
        }
    }
    else
    {
        if (speed.x>0)
        {
            speed.x = (speed.x > 1) ? speed.x/2 : 0;
        }
    }

    if (speed.y > max_speed.y)
    {
        speed.y = max_speed.y;
    }
    else if (speed.y < -max_speed.y)
    {
        speed.y = -max_speed.y;
    }

    //in boundaries
    if(y() >= view->world_size.bottom)
    {
        speed.y = (0 > speed.y) ? speed.y : 0 ;
        setY(view->world_size.bottom);
    }
    else if(y() <= view->world_size.top)
    {
        speed.y = (0 < speed.y) ? speed.y : 0 ;
        setY(view->world_size.top);
    }

    if(x()<=view->world_size.left)
    {
        speed.x = (0 < speed.x) ? speed.x : 0 ;
        setX(view->world_size.left);
    }
    else if(x() >= view->world_size.right)
    {
        speed.x = (0 > speed.x) ? speed.x : 0 ;
        setX(view->world_size.right);
    }

    update_collision_range(collision_ranges, size, speed);

    {
    QString temp_collision_type;
    QList<QGraphicsItem*> colliding_items;
    collision = QList<bool>{false,false,false};

    for(int i = 0; i < 3 ; i ++)
    {
        colliding_items = collision_ranges[i]->collidingItems();
        for(int j = 0; j < colliding_items.size(); j++)
        {
            temp_collision_type = collision_master->collide("Player",QString(typeid(*colliding_items[j]).name()));

            if(temp_collision_type == "simple_collision")
            {
                collision[i] = true;
                continue;
            }
            else if(temp_collision_type == "active_collision") //deactivates an active block
            {
                collision[i] = true;

                if(speed.y < -5)
                {
                    view->scene()->addItem(new Activated_block(pair{colliding_items[j]->x(),colliding_items[j]->y()}));

                    view->scene()->addItem(new Power_up_1(pair{colliding_items[j]->x(),colliding_items[j]->y()},block_size.x));

                    view->scene()->removeItem(colliding_items[j]);
                }

                continue;
            }
            else if(temp_collision_type == "add_coin") //collision with cheese
            {
                view->scene()->removeItem(colliding_items[j]);
                coin_counter->add_coin();
                continue;
            }

            else if(temp_collision_type == "power") //collision with power up
            {
                view->scene()->removeItem(colliding_items[j]);
                superpower(QString(typeid(*colliding_items[j]).name()));
                continue;
            }

            //else if(temp_collision_type == "lose_life") //collision with projectile hence dies and loses a life
            //{
            //    view->scene()->removeItem(colliding_items[j]);
            //    continue;
            //}


            else if(temp_collision_type == "damage_block_1") //collision with breakable block
            {
                collision[i] = true;
                if ((abs(speed.y) > 5 && i == 1) || (abs(speed.x) > 5 && i == 0)){
                    view->scene()->removeItem(colliding_items[j]);
                    view->scene()->addItem(new Breakable_block_2(pair{colliding_items[j]->x(), colliding_items[j]->y()}));
                }
                continue;
            }

            else if(temp_collision_type == "damage_block_2") //collision with breakable block
            {
                collision[i] = true;
                if ((abs(speed.y) > 5 && i == 1) || (abs(speed.x) > 5 && i == 0)){
                    view->scene()->removeItem(colliding_items[j]);
                    view->scene()->addItem(new Breakable_block_3(pair{colliding_items[j]->x(), colliding_items[j]->y()}));
                }

                continue;
            }

            else if(temp_collision_type == "damage_block_3") //collision with breakable block
            {
                collision[i] = true;
                if ((abs(speed.y) > 5 && i == 1) || (abs(speed.x) > 5 && i == 0)){
                    view->scene()->removeItem(colliding_items[j]);
                }
                continue;
            }

        }
    }
    }

    // movements of the player:
    if (collision[0])
    {
        speed.x = 0;
    }
    if (collision[1])
    {
        speed.y = 0;
    }
    if (collision[2] && !collision[1] && !collision[0])
    {
        speed.y = 0;
    }

    //Jump reset
    if(collision[1] && speed.y >= 0)
    {
        times_jumped = 0;
    }


    //Direction of the player:
    if (speed.x>0)
    {
        facing = Right;
    }
    else if (speed.x<0)
    {
        facing = Left;
    }


    //superpowers timer
    if (super)
    {
        count_super += 1;
    }
    if (count_super > 50)
    {
        super = false;
    }

    if (super_fast)
    {
        count_super_fast +=1;
    }
    if (count_super > 50)
    {
        super_fast = false;
    }

    if (super_throw)
    {
        count_super_throw +=1;
    }
    if (count_super > 50)
    {
        super_throw = false;
    }

    if (super_big)
    {
        count_super_big +=1;
    }
    if (count_super_big >50)
    {
        super_big = false;
    }

    if (super_invincible)
    {
        count_super_invincible +=1;
    }
    if (count_super_invincible >50)
    {
        super_invincible = false;
    }

    //animation
    count += 0.4;

    set_animation_state();

    if (count >= maxFrame[state])
    {
        count = 0;
    }
    if (count < 0)
    {
        count = maxFrame[state]-0.00001;
    }

    setPixmap(animations[super][facing][state][int(count)]);

    setPos(x()+speed.x,y()+speed.y);

    view->centerOn(this->x(), 0);

    view->update_background();
}

void Player::throw_projectile()
{

    // for the directino of the projectile: define a "last velocity speed"
    // then the direction is the direction of this last velocity
    pair position{x(),y()};

    switch (current_projectile)
    {
    case 1:
    {
        view->scene()->addItem(new Player_projectile_1(position, facing, size.x));
        break;
    }

    case 2:
    {
        view->scene()->addItem(new Player_projectile_2(position, facing, size.x));
        break;
    }

    case 3:
    {
        view->scene()->addItem(new Player_projectile_3(position, facing, size.x));
        break;
    }

    case 4:
    {
        view->scene()->addItem(new Enemy_projectile_1(position, facing, size.x));
        break;
    }
    }
}

void Player::superpower(QString collision_type)
{
    qDebug() << collision_type;
    if(collision_type == "10Power_up_1")
    {
        count_super_throw = 0;
        current_projectile = 3;
        super_throw = true;
    }
    else if(collision_type == "10Power_up_2")
    {
        count_super_fast = 0;
        speed.x = speed.x/2;
        super_fast = true;
    }
    else if(collision_type == "10Power_up_3")
    {
        count_super_big = 0;
        super_big = true;
    }
    else if(collision_type == "10Power_up_4")
    {
        count_super_invincible = 0;
        super_invincible = true;
    }
    else if(collision_type == "10Power_up_5")
    {
        count_super_big = 0;
        size.x*=2;
        size.y*=2;
        super_big = true;
        super = true;
    }
    else if(collision_type == "10Power_up_6")
    {
        count_super_fast = 0;
        speed.x *= 2;
        super_fast = true;
    }
    else if(collision_type == "10Power_up_7")
    {

    }
    else if(collision_type == "10Power_up_8")
    {
        count_super = 0;
        super = true;
    }
}

void Player::set_animation_state()
{
    switch(state)
    {
        case jumpH:
            if (count>=maxFrame[jumpH])
            {
                state = fallH;
            }
            break;

        case landH:
            if (count>=maxFrame[landH])
            {
                state = run;
            }
            break;

        case jumpV:
            if (count>=maxFrame[jumpV])
            {
                state = fallV;
            }
            break;

        case landV:
            if (count>=maxFrame[landV])
            {
                state = stand;
            }
            break;

        default:
            if (collision[1] && speed.y >= 0)
            {
                if (state==fallH)
                {
                    state = landH;
                }
                else if (state == fallV)
                {
                    state = landV;
                }
                else if (speed.x == 0.0)
                {
                    state = stand;
                }
                else
                {
                    state = run;
                }
            }
            else
            {
                if (speed.x == 0.0)
                {
                    state = fallV;
                }
                else
                {
                    state = fallH;
                }
            }
    }

    if (state != old_state)
    {
        old_state = state;
        count = 0;
    }
}

void Player::jump()
{
    if(times_jumped >= max_consecutive_jumps)
    {
        return;
    }
    times_jumped ++;
    speed.y = -max_speed.y;
    if (speed.x == 0.0)
    {
        state = jumpV;
    }
    else
    {
        state = jumpV;
    }
}

void Player::create_animation()
{
    QPixmap imgChar(gtexture->get_path_to(basic_player));

    for (int j = 0; j<number_of_character_states; j++)
    {
        for (int i = 0; i<maxFrame[j]; i++)
        {
            //generate images looking left
            animations[0][1][j][i] = imgChar.copy(int(i*size.x), int(j*size.y), int(size.x), int(size.y));

            //generate images looking right
            QImage img = imgChar.copy(int(i*size.x), int(j*size.y), int(size.x), int(size.y)).toImage();
            img = img.mirrored(true, false);
            animations[0][0][j][i] = QPixmap::fromImage(img);


            //Generate super images looking left
            animations[1][1][j][i] = imgChar.copy(int(i*size.x), int((number_of_character_states+j)*size.y), int(size.x), int(size.y));

            //Generate super images looking right
            QImage imgs = imgChar.copy(int(i*size.x), int((number_of_character_states+j)*size.y), int(size.x), int(size.y)).toImage();
            imgs = imgs.mirrored(true, false);
            animations[1][0][j][i] = QPixmap::fromImage(imgs);

        }
    }
}


