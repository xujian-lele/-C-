#include "iostream"
#include "pthread.h"
using namespace std;
int storage = 0;
pthread_mutex_t storage_mutex;
pthread_cond_t storage_empty;
pthread_cond_t storage_full;

void* produce(void* args)
{
    pthread_t pid = pthread_self();
    cout << "[" << pid << "]: in thread " << (*(int*)args) << endl;
    while(1)
    {
        pthread_mutex_lock(&storage_mutex);
        if(storage >= 10)
        {
            pthread_cond_wait(&storage_full,&storage_mutex);
        }
        else
        {
            cout << "before produce storage is: " << storage << "in [" << pid << "]: in thread " << (*(int*)args)<< endl;
            storage++;
            cout << "after  produce storage is: " << storage << "in [" << pid << "]: in thread " << (*(int*)args)<< endl;
            pthread_cond_signal(&storage_empty);
        }
        pthread_mutex_unlock(&storage_mutex);
    }
}

void* consume(void* args)
{
    pthread_t pid = pthread_self();
    cout << "[" << pid << "]: in thread " << (*(int*)args) << endl;
    while(1)
    {
        pthread_mutex_lock(&storage_mutex);
        if(storage <= 0)
        {
            pthread_cond_wait(&storage_empty, &storage_mutex);
        }
        else
        {
            cout << "before consume storage is: " << storage << "in [" << pid << "]: in thread " << (*(int*)args)<< endl;
            storage--;
            cout << "after  consume storage is: " << storage << "in [" << pid << "]: in thread " << (*(int*)args)<< endl;
            pthread_cond_signal(&storage_full);
        }
        pthread_mutex_unlock(&storage_mutex);
    }
}
int main()
{
    pthread_mutex_init(&storage_mutex,NULL);
    pthread_cond_init(&storage_empty,NULL);
    pthread_cond_init(&storage_full,NULL);

    pthread_t p1;
    pthread_t c1;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    //producer 1
    int index_p1 = 1;
    int res_p1 = pthread_create(&p1,&attr,produce,&index_p1);
    if(res_p1 != 0)
    {
        cout << "Pthread_create failed:producer 1" << endl;
    }
    //consumer 2
    int index_c1 = -1;
    int res_c1 = pthread_create(&c1,&attr,consume,&index_c1);
    if(res_c1 != 0)
    {
        cout << "Pthread_create failed: consumer 1" << endl;
    }
    pthread_attr_destroy(&attr);
    pthread_join(p1,NULL);
    pthread_join(c1,NULL);

    pthread_mutex_destroy(&storage_mutex);
    pthread_cond_destroy(&storage_empty);
    pthread_cond_destroy(&storage_full);
}
