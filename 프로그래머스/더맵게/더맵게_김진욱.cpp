#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 오름차순 pq;
    // priority_queue<int, vector<int>, greater<int>> pq;
    make_heap(scoville.begin(), scoville.end(), greater()); 
    
    //오름찻순으로 정렬했으므로 프론트에는 가장 안매운 맛. 
    while(scoville.front() < K && scoville.size() >= 2) {
        
        // 가장 작은 값을 맨뒤로
        pop_heap(scoville.begin(),scoville.end(), greater<int>());
        int smallest1 = scoville.back();
        //제거
        scoville.pop_back();

        pop_heap(scoville.begin(),scoville.end(), greater<int>());
        int smallest2 = scoville.back();
        scoville.pop_back();

        // 조합한 공식을 푸시백
        scoville.push_back(smallest1 + smallest2 * 2);
        
        
        push_heap(scoville.begin(),scoville.end(), greater<int>());

        answer ++;
    }

    return answer;
}