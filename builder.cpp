#include <iostream>

using namespace std;

namespace builder{
    class car{
        private:
            string _gears;
            string _brakes;
            string _wheels;
            string _body;
        public:
            void setGears(const string & gears){
                _gears = gears;
            }
            void setBrakes(const string & brakes){
                _brakes = brakes;
            }
            void setWheels(const string & wheels){
                _wheels = wheels;
            }
            void setBody(const string & body){
                _body = body;
            }
            void displayCar(){
                cout<<_gears<<endl
                    <<_brakes<<endl
                    <<_wheels<<endl
                    <<_body<<endl;
            }                                    
    };
    class carBuilder{
        public:
            virtual void buildGear()=0;
            virtual void buildBrake()=0;
            virtual void buildWheel()=0;
            virtual void buildBody()=0;
            virtual car * getCar()=0;
    };
    class luxuryCarBuilder:public carBuilder{
        private:
            car * _lCar;
        public:
            luxuryCarBuilder(){
                _lCar = new car();
            }
            void buildGear(){
                _lCar->setGears("Mini Gear");
            }
            void buildBrake(){
                _lCar->setBrakes("power brake");
            }
            void buildWheel(){
                _lCar->setWheels("costly wheels");
            }
            void buildBody(){
                _lCar->setBody("Luxury body");
            }
            car * getCar(){
                return _lCar;
            }
    };
    class economyCarBuilder:public carBuilder{
        private:
            car * _lCar;
        public:
            economyCarBuilder(){
                _lCar = new car();
            }
            void buildGear(){
                _lCar->setGears("low end Gear");
            }
            void buildBrake(){
                _lCar->setBrakes("low end brake");
            }
            void buildWheel(){
                _lCar->setWheels("cheap wheels");
            }
            void buildBody(){
                _lCar->setBody("economy body");
            }
            car * getCar(){
                return _lCar;
            }
    };
    class carManufacturer{
        private:
            carBuilder * _lcarBuilder;
        public:
            carManufacturer(carBuilder * lcarBuild):_lcarBuilder(lcarBuild){}
            void buildCar(){
                _lcarBuilder->buildWheel();
                _lcarBuilder->buildBrake();
                _lcarBuilder->buildGear();
                _lcarBuilder->buildBody();
            }
            car * getCar(){
                return _lcarBuilder->getCar();
            }
    };
}

using namespace builder;

int main(int argc,char * argv,char * argp[]){
    carBuilder * cb = new economyCarBuilder();
    carManufacturer * cm = new carManufacturer(cb);
    cm->buildCar();
    car * c = cm->getCar();
    c->displayCar();
    return 0;
}