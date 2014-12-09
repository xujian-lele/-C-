#include "pthread.h"
#include "iostream"
#define PTHRED_NUM 5
using namespace std;
int sum;
pthread_mutex_t sum_mutex;
class A
{
    public:
    static void* sayhello(void* args)
    {
        int i = *((int *)args);
        cout << "Hello..i am:" << i << endl;
        pthread_mutex_lock(&sum_mutex);
        cout << "before + sum is: " << sum <<"in thread" << i << endl;
        sum += i;
        cout << "after + sum is: " << sum <<"in thread" << i << endl;
        pthread_mutex_unlock(&sum_mutex);
        pthread_exit(0);
    }
};
int main()
{
    pthread_t tid[PTHRED_NUM];
    int index[PTHRED_NUM];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_mutex_init(&sum_mutex,NULL);
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
    }
    pthread_mutex_destroy(&sum_mutex);
    cout << "finally sum is: " << sum << endl;
}
