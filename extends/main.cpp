#include "iostream"
#include "algorithm"

using namespace std;
#define SIZE  20
int main(void){
    int array[SIZE];
    array[1] = 10000;
    int *p = find(array,array+SIZE,10000);
    if(p == array+SIZE){
        cout << "Not find" << endl;
    }else{
        cout << "Has find" << endl;
    }
    cout << *p << endl;
    return 0;
}
