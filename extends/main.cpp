#include "pthread.h"
#include "iostream"
#define PTHRED_NUM 5
using namespace std;
void* sayhello(void* args)
{
    cout << "Hello..." << endl;
}
int main()
{
    pthread_t tid[PTHRED_NUM];
    for(int i=0;i<PTHRED_NUM;i++)
    {
        int ret = pthread_create(&tid[i], NULL, sayhello, NULL);
    }
    pthread_exit(NULL);
}
