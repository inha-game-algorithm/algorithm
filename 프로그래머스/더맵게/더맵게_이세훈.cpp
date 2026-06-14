#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> queue;

    for (int s : scoville)
    {
        queue.push(s);
    }

    while (!queue.empty())
    {
        if (queue.top() >= K) return answer;
        int a = queue.top();
        queue.pop();

        if (queue.empty()) return -1;

        int b = a + (queue.top() * 2);
        queue.pop();
        queue.push(b);
        ++answer;
    }

    return answer;
}