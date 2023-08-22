#include <iostream>
#include <cassert>
#include <memory>
#include <unordered_map>


#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <gl\wgl.h>
//#include <GL\freeglut.h>

#include "Unit.h"
#include "Archer.h"
#include "Transport.h"


int main() {

    auto car = std::make_unique<unit::Transport>();

    assert(car->getSpeed() >= 0.0);

    auto car2 = dynamic_cast<unit::Unit *> (car.get());

    assert(car2);

    assert(car.get() == car2);

    car2 = std::move(car.get());

    car2->go();

    car2->getLevel();







    return 0;
}
