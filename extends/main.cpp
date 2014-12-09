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
    }
};
int main()
{
    pthread_t tid[PTHRED_NUM];
    int index[PTHRED_NUM];
    for(int i=0;i<PTHRED_NUM;i++)
    {
        index[i] = i;
        int ret = pthread_create(&tid[i], NULL, A::sayhello, (void*)&index[i]);
        if(ret != 0)
        {
            cout << "pthread_create():error:" << ret << endl;
        }
    }

    for(int i=0; i<PTHRED_NUM; i++)
    {
        pthread_join(tid[i],NULL);
    }
}
