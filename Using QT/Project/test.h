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

    //tests for collectable class
    bool Test_ColUp();
    bool Test_ColDown();
    bool Test_ColRight();
    bool Test_ColLeft();

};

#endif // TEST_H
