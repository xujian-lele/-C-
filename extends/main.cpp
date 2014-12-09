#include "pthread.h"
#include "iostream"
#define PTHRED_NUM 5
using namespace std;
class A
{
    public:
    static void* sayhello(void* args)
    {
        int i = *((int *)args);
        cout << "Hello..i am:" << i << endl;
        void* status = (void*)(i + 10);
        pthread_exit(status);
    }
};
int main()
{
    pthread_t tid[PTHRED_NUM];
    int index[PTHRED_NUM];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for(int i=0;i<PTHRED_NUM;i++)
    {
        index[i] = i;
        int ret = pthread_create(&tid[i],&attr, A::sayhello, (void*)&index[i]);
        if(ret != 0)
        {
            cout << "pthread_create():error:" << ret << endl;
        }
    }
pthread_attr_destroy(&attr);
void* status;
    for(int i=0; i<PTHRED_NUM; i++)
    {
        int res = pthread_join(tid[i],&status);
        if(res != 0)
        {
            cout << "pthread_join():failed" << tid[i] << endl;
        }
        else
        {
            cout << "pthread_join():get status:" << (long)status << endl;
        }
    }
}
