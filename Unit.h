#ifndef GAME_UNIT_H
#define GAME_UNIT_H


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

        [[nodiscard]] float getSpeed() const noexcept;

        [[nodiscard]] float getLevel() const noexcept;

        /** Set the speed.*/
        void setSpeed(float speed);

        /** Set the level.*/
        void setLevel(float level);


    private:
        float level = 0.0;
        float speed = 0.0;


    };

}


#endif //GAME_UNIT_H
