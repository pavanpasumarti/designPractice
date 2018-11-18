#include <iostream>
#include <map>

using namespace std;

namespace prototype{
    class storage{
        protected:
            string _type;
        public:
            static map<const string,storage *> objStore;
            virtual storage * clone()=0;
            void displayType(){
                cout<<_type<<endl<<this<<endl;
            }
            static map<const string,storage *> initMap();
    };
    class fileStore:public storage{
        public:
            fileStore(string type){
                _type = type;
            }
            storage * clone(){
                return new fileStore(*this);
            }
    };
    class dbStore:public storage{
        public:
            dbStore(string type){
                _type = type;
            }
            storage * clone(){
                return new dbStore(*this);
            }
    };
    map<const string,storage *> storage::initMap(){
        map<const string,storage *> temp;
        temp["FILE"] = new fileStore("file");
        temp["DB"] = new dbStore("db");
        return temp;
    }
    map<const string,storage *> storage::objStore = storage::initMap();
}

using namespace prototype;
int main(int argc,char * argv[],char * argp[]){
    cout<<storage::objStore["FILE"]<<endl;
    cout<<storage::objStore["DB"]<<endl;
    storage * fileClone = storage::objStore["FILE"]->clone();
    fileClone->displayType();
    storage * dbClone = storage::objStore["DB"]->clone();
    dbClone->displayType();
    return 0;
}