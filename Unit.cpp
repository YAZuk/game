#include <iostream>
#include "Unit.h"

namespace unit {
    Unit::Unit() {
        std::cout << "default Unit::Unit()" << std::endl;
    }

    Unit::Unit(const unit::Unit &other) {
        std::cout << "copy const unit::Unit &other" << std::endl;

    }

    Unit::Unit(const unit::Unit &&other) {
        std::cout << "move const unit::Unit &&other" << std::endl;
    }


    Unit::~Unit() {
        std::cout << "Unit::~Unit()" << std::endl;
    }

    void Unit::fly() {

    }

    void Unit::go() {

    }

    float Unit::getLevel() const noexcept {
        return level;
    }

    float Unit::getSpeed() const noexcept {
        return speed;
    }

    void Unit::setSpeed(float speed) noexcept {
        Unit::speed = speed;
    }

    void Unit::setLevel(float level) noexcept {
        Unit::level = level;
    }

}

