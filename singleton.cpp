#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

namespace singleton{
    class single{
        public:
        static single * inst;
        static pthread_mutex_t mut1;
        static void * getInstance(void *);
        private:
        single(){
            cout<<"i'm ctor"<<endl;
        }
        single(const single& iSingle){
        }  
    };
    single * single::inst = NULL;
    pthread_mutex_t single::mut1 = PTHREAD_MUTEX_INITIALIZER;
    void * single::getInstance(void *){
        if(!inst){
            //sleep(2);
            pthread_mutex_lock(&mut1);
            if(!inst)
                inst = new single();
            pthread_mutex_unlock(&mut1);
        }
        cout<<inst<<endl;
        return inst;
    }
}
using namespace singleton;
int main(int argc,char * argv[],char * argp[]){
    pthread_t t1,t2;
    int i_t1 = pthread_create(&t1,NULL,single::getInstance,NULL);
    int i_t2 = pthread_create(&t2,NULL,single::getInstance,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;

}