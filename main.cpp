#include <iostream>
#include <cassert>
#include <memory>


#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>

#include "Unit.h"
#include "Transport.h"


int main() {

    auto car = std::make_unique<unit::Transport>();

    
    assert(car->getSpeed() >= 0.0);

    auto car2 = dynamic_cast<unit::Unit*> (car.get());

    assert(car2);






//
//    unit::Unit unit2(std::move(unit1));




    return 0;
}
