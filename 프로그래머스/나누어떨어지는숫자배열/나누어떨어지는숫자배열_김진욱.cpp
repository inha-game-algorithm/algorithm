#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    // 벡터를 일단 순회
    for(int i : arr){
        // divisor 값으로 i를 나눠서 0으로 떨어지면
        if(i % divisor == 0){
            // 값을 일단 후방에 삽입
            answer.push_back(i);
        }
    }
    // for를 타지 못한 경우 사이즈가 0이므로
    if(answer.size()==0) {
        // 강제로 -1값 푸시백
        answer.push_back(-1);
    }
    
    // 알고리즘 정렬 함수 사용
    std::sort(answer.begin(), answer.end());
    
    // 제출
    return answer;
}