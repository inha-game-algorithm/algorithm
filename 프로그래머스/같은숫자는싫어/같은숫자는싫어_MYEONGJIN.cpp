#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> v;
    
    if (!arr.empty())
    {
        v.push_back(arr[0]);
        for (size_t i = 1; i < arr.size(); ++i)
            if (arr[i] != arr[i - 1])
                v.push_back(arr[i]);
    }
    
    return v;
}
