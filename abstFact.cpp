#include <iostream>

using namespace std;

namespace abstfact{
    typedef enum carModels{TOYOTA,HONDA} models;
    typedef enum locations{INDIA,USA} locs;
    typedef enum bikeModels{BMW,DUCATI} bModels;
    class car{
        public:
        locs _loc;
        car(const locs& loc):_loc(loc){}
        virtual void whoami(){
            cout<<"generic Car"<<endl;
        }
    };
    class toyota:public car{
        public:
            toyota(locs loc):car(loc){}
            void whoami(){
                cout<<"Toyota "<<_loc<<endl;
            }
    };
    class honda:public car{
        public:
            honda(locs loc):car(loc){}
            void whoami(){
                cout<<"Honda "<<_loc<<endl;
            }
    };
    class bike{
        public:
        locs _loc;
        bike(const locs& loc):_loc(loc){}
        virtual void whoami(){
            cout<<"generic bike"<<endl;
        }
    };
    class bmw:public bike{
        public:
            bmw(locs loc):bike(loc){}
            void whoami(){
                cout<<"Bmw "<<_loc<<endl;
            }
    };
    class ducati:public bike{
        public:
            ducati(locs loc):bike(loc){}
            void whoami(){
                cout<<"Ducati "<<_loc<<endl;
            }
    };
    class abFact{
        public:
        virtual car* getCar(const models& model)=0;
        virtual bike* getBike(const bModels& bmodel)=0;
        static abFact* getFactory();
    };

    class IndiaFactory:public abFact{
        public:
        car* getCar(const models& model){
            switch(model){
                case TOYOTA:
                    return new toyota(INDIA);
                case HONDA:
                    return new honda(INDIA);

            }             
        }
        bike* getBike(const bModels& bmodel){
            switch(bmodel){
                case BMW:
                    return new bmw(INDIA);
                case DUCATI:
                    return new ducati(INDIA);

            }             
        }
    };

    class UsaFactory:public abFact{
        public:
        car* getCar(const models& model){
            switch(model){
                case TOYOTA:
                    return new toyota(USA);
                case HONDA:
                    return new honda(USA);

            }             
        }
        bike* getBike(const bModels& bmodel){
            switch(bmodel){
                case BMW:
                    return new bmw(USA);
                case DUCATI:
                    return new ducati(USA);

            }             
        }
    };
    abFact* abFact::getFactory(){
        locs loc = USA; //need to implement this based on somee GPS logic.
        switch(loc){
            case INDIA:
                return new IndiaFactory();
            case USA:
                return new UsaFactory();

        } 
    }
}

int main(int args,char * argv[],char * argp[]){
    using namespace abstfact;
    //client doesn't know which factory he is calling.
    //we can still replace TOYOTA/BMW ... params below
    //with something else such that client is not specifying the car
    //but some feature based on which factory can invoke exact
    //instance.
    car* myCar = abFact::getFactory()->getCar(TOYOTA);
    bike* myBike = abFact::getFactory()->getBike(BMW);
    car* myNewCar = abFact::getFactory()->getCar(HONDA);
    bike* myNewBike = abFact::getFactory()->getBike(DUCATI);
    myCar->whoami();
    myBike->whoami();
    myNewCar->whoami();
    myNewBike->whoami();
    return 0;              
}