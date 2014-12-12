#include "iostream"
#include "list"
#include "algorithm"

using namespace std;
bool dayu100(int x){
    bool b = (x > 100);
    return b;
}
class a{
public :
    a(){
    }
    ~a(){
    }
    virtual void f(int x){};
};
typedef list<int> int_list;
int main(void)
{
    int_list lst;
    int_list lst1;
    for(int i=10;i>=0;i--){
        lst.push_back(i);
    }
    cout << lst.front() << endl;
    cout << lst.back() << endl;

    for(int i=100;i<105;i++){
        lst1.push_back(i);
    }
    lst.merge(lst1);
cout << lst.size() << endl;
lst.remove_if(dayu100);
cout << lst.size() << endl;
cout << lst.back() << endl;

a A;
cout << sizeof(A) << endl;
}
