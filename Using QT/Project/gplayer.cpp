#include "gplayer.h"
#include "listheaders.h"

GPlayer::GPlayer(QPoint position, QPoint speed, QPoint size, QGraphicsItem *parent):
    GMovingObject(speed, position, parent), Super_powers()
{
    create_animation(size);

    setPixmap(animations[supers_b[super]][facing][state][int(count)]);

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();

    setZValue(layer_player);

    size.setY(0);

    coin_counter = new Coin_counter(size,this);

    clock = new GClock(60);

    view->scene->addItem(clock);
}

GPlayer::~GPlayer()
{
    view->player = nullptr;

    coin_counter->deleteLater();

    delete(clock);
}

QString GPlayer::get_name()
{
    return "Player";
}

void GPlayer::move()
{
    effect_forces();

    check_in_boundaries();

    update_collision_range();

    qreal speedy = speed.y();

    collide();

    if(speedy > 0 && speedy != speed.y())
    {
        touching_ground = true;
    }
    else
    {
        touching_ground = false;
    }

    //Jump reset
    if(touching_ground)
    {
        times_jumped = 0;
    }


    //Direction of the player:
    if (speed.rx() > 0)
    {
        facing = Right;
    }
    else if (speed.rx() < 0)
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

    update_counters();

    setPixmap(animations[supers_b[super]][facing][state][int(count)]);

    setPos(x()+speed.rx(),y()+speed.ry());

    view->centerOn(this->x(), 0);

    view->update_background();

    clock->update();

    switch(gstate)
    {
    case Dead:
    {
        view->game_over();
        break;
    }
    case Win:
    {
        view->you_win();
        break;
    }
    default:
    {
        break;
    }
    }
}

void GPlayer::keyPressEvent(QKeyEvent *event)
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

void GPlayer::keyReleaseEvent(QKeyEvent *event)
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

void GPlayer::create_animation(QPoint size)
{
    QPixmap imgChar(gtexture->get_path_to(basic_player));

    for (int j = 0; j<number_of_character_states; j++)
    {
        for (int i = 0; i<maxFrame[j]; i++)
        {
            //generate images looking right
            animations[0][1][j][i] = imgChar.copy(i*size.rx(), j*size.ry(), size.rx(), size.ry());

            //generate images looking left
            QImage img = imgChar.copy(i*size.rx(), j*size.ry(), size.rx(), size.ry()).toImage();
            img = img.mirrored(true, false);
            animations[0][0][j][i] = QPixmap::fromImage(img);


            //Generate super images looking right
            animations[1][1][j][i] = imgChar.copy(i*size.rx(), (number_of_character_states+j)*size.ry(), size.rx(), size.ry());

            //Generate super images looking left
            QImage imgs = imgChar.copy(i*size.rx(), (number_of_character_states+j)*size.ry(), size.rx(), size.ry()).toImage();
            imgs = imgs.mirrored(true, false);
            animations[1][0][j][i] = QPixmap::fromImage(imgs);

        }
    }
}

void GPlayer::effect_forces()
{
    //Accelerate
    speed.ry() += 1;

    //Motion smooth
    if (pressed_left)
    {
        if (speed.rx() > -max_speed.rx()*get_speed())
        {
            speed.rx() -= 1;
        }
    }
    else
    {
        if (speed.rx() < 0)
        {
            speed.rx() = (speed.rx() < -1) ? speed.rx()/2 : 0;
        }
    }

    if (pressed_right)
    {
        if (speed.rx() < max_speed.rx()*get_speed())
        {
            speed.rx() += 1;
        }
    }
    else
    {
        if (speed.rx() > 0)
        {
            speed.rx() = (speed.rx() > 1) ? speed.rx()/2 : 0;
        }
    }

    if (speed.ry() > max_speed.ry())
    {
        speed.ry() = max_speed.ry();
    }
    else if (speed.ry() < -max_speed.ry())
    {
        speed.ry() = -max_speed.ry();
    }
}

void GPlayer::set_animation_state()
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
            if (touching_ground)
            {
                if (state==fallH)
                {
                    state = landH;
                }
                else if (state == fallV)
                {
                    state = landV;
                }
                else if (speed.rx() == 0.0)
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
                if (speed.rx() == 0.0)
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

void GPlayer::throw_projectile()
{
    QPoint position(x(),y());

    if ( supers_b[super_wine])
    {
        view->scene->addItem(new Player_projectile_2(position, facing, sizex, get_throw_speed()));
    }

    else
    {
        view->scene->addItem(new Player_projectile_1(position, facing, sizex, get_throw_speed()));
    }

}

void GPlayer::jump()
{
    if(times_jumped >= max_consecutive_jumps + ((supers_b[super_jump]) ? 1 : 0) )
    {
        return;
    }
    times_jumped ++;
    speed.setY(-max_speed.ry());
    if (speed.rx() == 0)
    {
        state = jumpV;
    }
    else
    {
        state = jumpH;
    }
}

