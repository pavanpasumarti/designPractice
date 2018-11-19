#include <iostream>

using namespace std;
namespace adapter{
    //adaptee
    class flatSocket{
        public:
            void plugIn(){
                cout<<"Plugged into USA Socket"<<endl;
            }
    };
    //client is in USA and got india charger and expects india 
    //cahrger to plug into USA socket
    class roundSocket{
        public:
            virtual void insert()=0;
    };
    //converter from india to USA
    //client uses the adapter and still
    //plugs into india socket at one end
    //the other end will be usa socket.
    //composition
    class roundToFlatConverter:public roundSocket{
        public:
            flatSocket * _usSocket;
            roundToFlatConverter(){
                _usSocket = new flatSocket();
            }
            void insert(){
                _usSocket->plugIn();
            }
    };
}
using namespace adapter;

int main(int argc,char * argv[],char * argp[]){
    roundToFlatConverter * rfc = new roundToFlatConverter();
    rfc->insert();
    return 0;
}