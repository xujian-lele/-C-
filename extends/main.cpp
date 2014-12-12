#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int main(void){
    vector<int> vec;
    vec.push_back(100);
    vector<int>::iterator itr;
    itr = find(vec.begin(),vec.end(),1000);
    if(itr == vec.end()){
        cout << "not find" << endl;
    }else{
        cout << "find" << endl;
    }
    return 0;
}
