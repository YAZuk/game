#ifndef GAME_UNIT_H
#define GAME_UNIT_H



namespace unit {

    class Unit {

    public:
        Unit();

        Unit(const Unit &other);

        Unit(const Unit &&other);

        virtual void go();

        virtual void fly();

        virtual ~Unit();

    private:
        double speed = 0.0;
        double level = 0.0;



    };

}


#endif //GAME_UNIT_H
