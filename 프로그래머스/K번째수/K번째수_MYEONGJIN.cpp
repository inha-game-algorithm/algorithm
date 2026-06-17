#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 퀵 정렬 함수
void quickSort(std::vector<int>& arr, int start, int end) {
    if (start >= end) return; 

    int pivot = start; 
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] <= arr[pivot]) left++;
        while (right > start && arr[right] >= arr[pivot]) right--;

        if (left > right) {
            swap(arr[pivot], arr[right]);
        } else {
            swap(arr[left], arr[right]);
        }
    }

    quickSort(arr, start, right - 1);
    quickSort(arr, right + 1, end);
}


int k(vector<int> array, vector<int> commands)
{
    vector<int> n(array.begin() + commands[0] - 1, array.begin() + commands[1]);
    
    //sort(n.begin(), n.end());
    quickSort(n, 0, n.size() - 1);
    
    return n[commands[2] - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{   
    vector<int> r;
    
    for (int i = 0; i < commands.size(); ++i)
    {
        r.push_back(k(array, commands[i]));
    }
    
    return r;
}

