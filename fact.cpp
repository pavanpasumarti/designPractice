#include <iostream>

using namespace std;

namespace cars{
    typedef enum carModels {Hyundai,Volkswagon} Models;
 
    class car{
       
    protected:
        string _type;
        car(const string & type):_type(type){}
    public:
        void setType(const string& type){
            _type = type;
        }
        string getType(){
            return _type;
        }
        virtual void whoami(){
            cout<<"generic car"<<endl;
        }
        static car * makeCar(Models model,const string& type);  
    };
  
    class hyundai:public car{
        public:
            hyundai(string _type):car(_type){}
            void whoami(){
                cout<<"Hyundai "<<_type<<endl;
            }
    };
    class volkswagon:public car{
        public:
            volkswagon(string _type):car(_type){}
            void whoami(){
                cout<<"volkswagon "<<_type<<endl;
            }
    };

    car * car::makeCar(Models model,const string& type){
        switch(model){
            case Hyundai:
                return new hyundai(type);
            case Volkswagon:
                return new volkswagon(type);

        }             
    }
}


int main(int args,char * argv[],char * argp[]){
    using namespace cars;
    car * car1 = car::makeCar(Hyundai,"HatchBack");
    car * car2 = car::makeCar(Volkswagon,"Luxury");
    car1->whoami();
    car2->whoami();
}