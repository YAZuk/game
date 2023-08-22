#ifndef GAME_UNIT_H
#define GAME_UNIT_H
#include <string>

namespace unit {
    /**
     * @brief Базовый класс юнита
     */
    class Unit {

    public:
        Unit();

        Unit(const Unit &other);

        Unit(const Unit &&other);

        virtual void go();

        virtual void fly();

        virtual ~Unit();

        [[nodiscard]] virtual float getSpeed() const noexcept;

        [[nodiscard]] virtual float getLevel() const noexcept;

        /** Установить скорость*/
        virtual void setSpeed(float speed);

        /** Установить уровень состояния юнита*/
        virtual void setLevel(float level);


    private:
        float level = 0.0;
        float speed = 0.0;
        std::string name = "";



    };

}


#endif //GAME_UNIT_H
