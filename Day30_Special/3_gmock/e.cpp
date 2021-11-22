#include "e.h"

carEmulator::carEmulator() {

}

void carEmulator::run(const userInput &_u) {
    if (_u.ignite || this->ignite) {
        this->ignite = true;
        this->rpm    = this->calculateRPM(_u.acc);
        this->gear   = this->calculateGear(_u.gear);
        this->speed  = this->calculateSpeed();
    }
}

someEmulator::someEmulator() {
    std::cout << "SomeEmulator" << std::endl;
}

int someEmulator::calculateGear(int gear) {
    std::cout << "The Gear is: " << gear << std::endl;
    return -1;
}

int someEmulator::calculateRPM(int acc) {
    std::cout << "The acc is: " << acc << std::endl;
    return -1;
}
