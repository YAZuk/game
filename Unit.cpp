//
// Created by LATYPOVR on 22.08.2023.
//
#include <iostream>
#include "Unit.h"

namespace unit {
    Unit::Unit() {
        std::cout <<"Unit::Unit()"<< std::endl;
    }

    Unit::Unit(const unit::Unit &other) {
        std::cout <<"const unit::Unit &other"<< std::endl;

    }

    Unit::Unit(const unit::Unit &&other) {
        std::cout <<"const unit::Unit &&other"<< std::endl;
    }


    Unit::~Unit() {
        std::cout <<"Unit::~Unit()"<< std::endl;
    }

    void Unit::fly() {

    }

    void Unit::go() {

    }

}

