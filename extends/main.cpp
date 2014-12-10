#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
int main(void)
{
    //STL中的vector
    vector<int> vector_int;
    int element;
    while(cin >> element)
    {
        vector_int.push_back(element);
    }
    //sort是STL中的算法
    sort(vector_int.begin(), vector_int.end());
    //vector能像数组那样进行访问
    for(int i=0;i<vector_int.size();i++)
    {
        cout << vector_int[i] << endl;
    }
}
