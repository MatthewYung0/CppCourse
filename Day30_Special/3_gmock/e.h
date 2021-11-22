#ifndef E_H
#define E_H
#include <iostream>

struct userInput {
    int acc = 0;
    int gear = 0;
    bool ignite = false;
    userInput(int a, int g, bool i):acc(a), gear(g), ignite (i){}
};

class carEmulator {
    int speed = 0;
    int rpm = 0;
    int gear = 0;
    bool ignite = false;
public:
    carEmulator();
    void run(const struct userInput &_u);
    virtual int calculateRPM(int acc) = 0;
    virtual int calculateGear(int gear) = 0;
    /*inline*/ int calculateSpeed() {return this->rpm * this->gear;}

};

class someEmulator : public carEmulator {
public:
    someEmulator();
    int calculateGear(int gear) override;
    int calculateRPM(int acc) override;
};

#endif // E_H
