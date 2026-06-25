#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    // 인접 리스트 생성
    vector<vector<int>> graph(n + 1);
    for (const auto& e : edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    // 거리 배열 대신 방문 여부만 체크하는 배열 사용 (메모리 및 속도 이점)
    vector<char> visited(n + 1, 0);
    queue<int> q;

    q.push(1);
    visited[1] = 1;

    int answer = 0;

    // BFS 탐색
    while (!q.empty())
    {
        // 현재 레벨에 있는 노드의 개수
        int q_size = q.size();

        answer = q_size;

        for (int i = 0; i < q_size; ++i)
        {
            int curr = q.front();
            q.pop();

            for (int next : graph[curr])
            {
                if (!visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    return answer;
}

// 보통 visited 배열을 인트로 사용하는데 char타입도 가능하다는거 보여주고싶어서 했음
//
// 큐의 현재 크기만큼만 반복해서 꺼내는 방식을 써서 현재 깊이에 잇는 노드들을 한번에 처리할 수 있음
// 탐색 계속하면서 answer에 현재 노드 계속 덮어씌우면 while 끝낫을 때 가장 먼 거리의 노드 개수만 answer에 남기 때문에
// 굳이 마지막에 배열을 한번 더 탐색 할 필요가 없음
