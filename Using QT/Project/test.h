#ifndef TEST_H
#define TEST_H
#include <QObject>
#include <QKeyEvent>

class Test: public QObject
{
    Q_OBJECT

public:
    Test();

    //tests for block/blocks classes
    bool Test_Blink();
    bool Test_Blink2();
    bool Test_Blocks();

    //tests for coin_counter class
    bool Test_AddCoin();
    bool Test_UpdateCounter();
    bool Test_CoinCount();

    //tests for tools
    bool Test_CreateColRange();
    bool Test_UpdateColRange();
    bool Test_Delay();
    bool Test_Tools();

    //tests for enemy
    bool Test_Jump();
    bool Test_Move_First();
    bool Test_Move_Second();
    bool Test_Move_Third();
    bool Test_Move();
    bool Test_TimerConnect();
    bool Test_Enemy();

    //tests for super_powers
    bool Test_UpdateCounter_SP();
    bool Test_PowerUp();
    bool Test_Speed_ThrowSpeed();
    bool Test_SuperPow();

    //tests for projectile
    bool Test_Move_Projectile();

    //tests for player
    bool Test_KeyEvents(QKeyEvent *event);
    bool Test_Move_Player();
    bool Test_Animation_State();
    bool Test_Jump_Player();

    //tests for menu
    bool Test_KeyPressEvent();

    //every test
    void All_Tests();

};

#endif // TEST_H
