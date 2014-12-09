#include "iostream"
#include "pthread.h"
#define BOUND 5
using namespace std;
int task = 10;
pthread_mutex_t task_mutex;
pthread_cond_t task_cond;
void* sayhello1(void* args)
{
    pthread_t pid = pthread_self();
    cout << "[" << pid << "] hello in thread " <<  *( ( int* )args ) << endl;
    bool is_signaled = false;
    while(1)
    {
        pthread_mutex_lock(&task_mutex);
        if(task > BOUND)
        {
            cout << "[" << pid << "] take task: " << task << " in thread " << *( (int*)args ) << endl;
            task--;
        }
        else if(!is_signaled)
        {
            cout << "[" << pid << "] pthread_cond_signal in thread " << *( ( int* )args ) << endl;
            pthread_cond_signal(&task_cond);
        }
        pthread_mutex_unlock(&task_mutex);
        if(task == 0)
        {
            break;
        }
    }
}

void* sayhello2(void* args)
{
    pthread_t pid = pthread_self();
    cout << "[" << pid << "] hello in thread " <<  *( ( int* )args ) << endl;
    while(1)
    {
        pthread_mutex_lock(&task_mutex);
        if(task > BOUND)
        {
            cout << "[" << pid << "] pthread_cond_signal in thread " << *( ( int* )args ) << endl;
            pthread_cond_wait(&task_cond,&task_mutex);
        }
        else
        {
            cout << "[" << pid << "] take task: " << task << " in thread " << *( (int*)args ) << endl;
            task--;
        }
        pthread_mutex_unlock(&task_mutex);
        if(task == 0)
        {
            break;
        }
    }
}
int main()
{

    pthread_mutex_init(&task_mutex,NULL);
    pthread_cond_init(&task_cond,NULL);

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

    pthread_t tid1;
    int index1 = 1;
    int res1 = pthread_create(&tid1,&attr,sayhello1,(void*) &index1);
    if(res1 != 0)
    {
        cout << "pthread_create error in creating" << index1 << " thread" <<endl;
    }

    pthread_t tid2;
    int index2 = 2;
    int res2 = pthread_create(&tid2,&attr,sayhello2,(void*) &index2);
    if(res2 != 0)
    {
        cout << "pthread_create error in creating" << index2 << " thread" <<endl;
    }

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    pthread_mutex_destroy(&task_mutex);
    pthread_cond_destroy(&task_cond);
    return 0;
}
