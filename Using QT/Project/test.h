#ifndef TEST_H
#define TEST_H
#include <QObject>

class Test: public QObject
{
    Q_OBJECT

public:
    Test();

    //tests for block/blocks classes
    bool Test_Blink();
    bool Test_Blink2();
    void Test_Blocks(); //tells us if all the tests from this classes are succesful

    //tests for coin_counter class
    bool Test_AddCoin();
    bool Test_UpdateCounter();
    void Test_CoinCount();

    //tests for tools
    bool Test_CreateColRange();
    bool Test_UpdateColRange();
    bool Test_Delay();
    void Test_Tools();

};

#endif // TEST_H
