#include "listheaders.h"

Player::Player(QGraphicsItem* parent) :
    QObject(), QGraphicsPixmapItem (parent)
{
    create_animation();

    collision_ranges = create_collision_range<Player>(this);

    this->setZValue(layer_player);

    super_powers = new Super_powers();

    // Timer
    timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));

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

void Player::update()
{
    move();
}

void Player::move()
{
    //Accelerate
    speed.y += 1;

    //Motion smooth
    if (pressed_left)
    {
        if (speed.x>-max_speed.x*super_powers->get_speed())
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
        if (speed.x<max_speed.x*super_powers->get_speed())
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
        view->game_over();
    }
    else if(y() <= view->world_size.top)
    {
        //please stop blocking us at the top, it's anoying
        //speed.y = (0 < speed.y) ? speed.y : 0 ;
        //setY(view->world_size.top);
    }

    if(x()<=view->world_size.left)
    {
        speed.x = (0 < speed.x) ? speed.x : 0 ;
        setX(view->world_size.left);
    }
    else if(x() >= view->world_size.right-size.x)
    {
        speed.x = (0 > speed.x) ? speed.x : 0 ;
        setX(view->world_size.right-size.x);
    }

    update_collision_range(collision_ranges, size, speed);

    {
    QString temp_collision_type;
    QList<QGraphicsItem*> colliding_items;
    collision = QList<bool>{false,false,false};

    for(int i = (super_powers->supers_b[super_invincible] && i==0) ? 1 : 0; i < 3 ; i ++)
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
                    view->scene->addItem(new Activated_block(pair{colliding_items[j]->x(),colliding_items[j]->y()}));

                    create_random_powerup(pair{colliding_items[j]->x(),colliding_items[j]->y()},block_size.y);

                    view->scene->removeItem(colliding_items[j]);
                }

                continue;
            }
            else if(temp_collision_type == "add_coin") //collision with cheese
            {
                view->scene->removeItem(colliding_items[j]);
                coin_counter->add_coin();
                continue;
            }

            else if(temp_collision_type == "power") //collision with power up
            {
                view->scene->removeItem(colliding_items[j]);

                QChar last_char = (QString(typeid(*colliding_items[j]).name()))[11];

                for(int i = 0; i < supers_count;i++)
                {
                    //qDebug() << (char(i) == last_char);
                    //qDebug() << char(i);
                    //qDebug() << last_char;
                    if(QChar(i) == last_char)
                    {
                        super_powers->power_up(i);
                    }
                }
                continue;
            }

            //else if(temp_collision_type == "lose_life") //collision with projectile hence dies and loses a life
            //{
            //    view->scene->removeItem(colliding_items[j]);
            //    continue;
            //}


            else if(temp_collision_type == "damage_block_1") //collision with breakable block
            {
                collision[i] = true;
                if ((abs(speed.y) > 5 && i == 1) || (abs(speed.x) > 5 && i == 0))
                { //regular collision
                    view->scene->removeItem(colliding_items[j]);
                    view->scene->addItem(new Breakable_block_2(pair{colliding_items[j]->x(), colliding_items[j]->y()}));
                }

                if ((abs(speed.y) > 9 && i == 1) || (abs(speed.x) > 9 && i == 0))
                { //if player is super fast, he destroys the block directly
                    view->scene->removeItem(colliding_items[j]);
                }
                continue;
            }

            else if(temp_collision_type == "damage_block_2") //collision with breakable block
            {
                collision[i] = true;
                if ((abs(speed.y) > 5 && i == 1) || (abs(speed.x) > 5 && i == 0))
                { //regular collision
                    view->scene->removeItem(colliding_items[j]);
                    view->scene->addItem(new Breakable_block_3(pair{colliding_items[j]->x(), colliding_items[j]->y()}));
                }

                if ((abs(speed.y) > 9 && i == 1) || (abs(speed.x) > 9 && i == 0))
                { //if player is super fast, he destroys the block directly
                    view->scene->removeItem(colliding_items[j]);
                }
                continue;
            }

            else if(temp_collision_type == "damage_block_3") //collision with very broken block => break the block
            {
                collision[i] = true;
                if ((abs(speed.y) > 5 && i == 1) || (abs(speed.x) > 5 && i == 0))
                {
                    view->scene->removeItem(colliding_items[j]);
                }
                continue;
            }
            else if(temp_collision_type == "end_collision") //collision with end_block
            {
                view->you_win();
            }

            else if(temp_collision_type == "die") //collision with enemy
            {
                view->game_over();
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

    super_powers->update_counters();

    setPixmap(animations[super_powers->supers_b[super]][facing][state][int(count)]);

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
        view->scene->addItem(new Player_projectile_1(position, facing, size.x, super_powers->get_throw_speed()));
        break;
    }

    case 2:
    {
        view->scene->addItem(new Player_projectile_2(position, facing, size.x, super_powers->get_throw_speed()));
        break;
    }

    case 3:
    {
        view->scene->addItem(new Player_projectile_3(position, facing, size.x, super_powers->get_throw_speed()));
        break;
    }
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

Player::~Player()
{
    qDebug() << "die";

    timer->stop();
    timer->deleteLater();

    for(int i = 0; i < collision_ranges.size(); i++)
    {
        delete(collision_ranges[i]);
    }

    delete(coin_counter);
}

void Player::create_animation()
{
    QPixmap imgChar(gtexture->get_path_to(basic_player));

    for (int j = 0; j<number_of_character_states; j++)
    {
        for (int i = 0; i<maxFrame[j]; i++)
        {
            //generate images looking right
            animations[0][1][j][i] = imgChar.copy(int(i*size.x), int(j*size.y), int(size.x), int(size.y));

            //generate images looking left
            QImage img = imgChar.copy(int(i*size.x), int(j*size.y), int(size.x), int(size.y)).toImage();
            img = img.mirrored(true, false);
            animations[0][0][j][i] = QPixmap::fromImage(img);


            //Generate super images looking right
            animations[1][1][j][i] = imgChar.copy(int(i*size.x), int((number_of_character_states+j)*size.y), int(size.x), int(size.y));

            //Generate super images looking left
            QImage imgs = imgChar.copy(int(i*size.x), int((number_of_character_states+j)*size.y), int(size.x), int(size.y)).toImage();
            imgs = imgs.mirrored(true, false);
            animations[1][0][j][i] = QPixmap::fromImage(imgs);

        }
    }
}
