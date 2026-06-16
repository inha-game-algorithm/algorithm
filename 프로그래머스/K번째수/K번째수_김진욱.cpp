#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // quick sort가 이해가 안가서...
    
    for(int i = 0; i < commands.size(); ++i) {
        int j = commands[i][0]; // 2 4 1
        int k = commands[i][1]; // 5 4 7
        int n = commands[i][2]; // 3 1 3
        
        // cout << i << endl;
        // cout << commands[i][1] << endl;
        
        // array 2-1번째에서 ~ 0+4번째를 템프에 담고
        vector<int> temp(array.begin() + j - 1, array.begin() + k);
        
        // temp를 sort로 정렬.
        sort(temp.begin(), temp.end());
        
        // n에 지정한 index를 temp에 담은 애를 push_back
        answer.push_back(temp[n - 1]);
    }
    return answer;
}

