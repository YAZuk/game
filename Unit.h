#ifndef GAME_UNIT_H
#define GAME_UNIT_H


namespace unit {

    class Unit {

    public:
        Unit() noexcept ;

        Unit(const Unit &other) noexcept ;

        Unit(const Unit &&other) noexcept ;

        virtual void go() noexcept ;

        virtual void fly() noexcept ;

        virtual ~Unit();

        [[nodiscard]] float getSpeed() const noexcept ;

        [[nodiscard]] float getLevel() const;

        void setSpeed(float speed);

        void setLevel(float level);


    private:
        float level = 0.0;
        float speed = 0.0;


    };

}


#endif //GAME_UNIT_H
