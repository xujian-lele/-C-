#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
int main(void)
{
    //STL�е�vector
    vector<int> vector_int;
    int element;
    while(cin >> element)
    {
        vector_int.push_back(element);
    }
    //sort��STL�е��㷨
    sort(vector_int.begin(), vector_int.end());
    //vector���������������з���
    for(int i=0;i<vector_int.size();i++)
    {
        cout << vector_int[i] << endl;
    }
}
