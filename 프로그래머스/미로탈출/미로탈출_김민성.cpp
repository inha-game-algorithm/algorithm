#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Position
{
    int r, c;
};

const int dr[4] = { 0, 0, 1, -1 };   // 동, 서, 남, 북
const int dc[4] = { 1, -1, 0, 0 };

vector<vector<int>> BFS(const vector<string>& maps, int n, int m, int sr, int sc)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[sr][sc] = 0;

    queue<Position> q;
    q.push({ sr, sc });

    while (!q.empty())
    {
        Position cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= m))
                continue;
            if (maps[nr][nc] == 'X')
                continue;
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({ nr, nc });
        }
    }

    return dist;
}

int solution(vector<string> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    Position start{}, lever{}, exitPos{};

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (maps[r][c] == 'S') start = { r, c };
            else if (maps[r][c] == 'L') lever = { r, c };
            else if (maps[r][c] == 'E') exitPos = { r, c };
        }
    }

    // 시작점 -> 레버
    vector<vector<int>> distFromStart = BFS(maps, n, m, start.r, start.c);
    int toLever = distFromStart[lever.r][lever.c];

    if (toLever == -1) return -1;

    // 레버 -> 출구
    vector<vector<int>> distFromLever = BFS(maps, n, m, lever.r, lever.c);
    int toExit = distFromLever[exitPos.r][exitPos.c];

    if (toExit == -1) return -1;

    return toLever + toExit;
}

// BFS 2회 수행 — 두 구간 최단경로의 합 패턴
//
// 미로를 탈출하려면 반드시 시작점 -> 레버 -> 출구 순서를 거쳐야 함
// 레버를 당기지 않으면 출구로 나갈 수 없으므로, 이 순서는 강제된다.
// 따라서 전체 최단 경로는
//   (시작점에서 레버까지의 최단 거리) + (레버에서 출구까지의 최단 거리)
// 로 분리해서 계산할 수 있다. 각 구간은 독립적인 최단경로 문제이므로
// BFS 를 두 번 따로 수행하면 된다.

// BFS 는 X(벽)만 막고 E는 일반 통로처럼 취급해서 그냥 지나간다.
// 즉 시작점 -> 레버 구간의 BFS 에서 출구 칸을 그냥 통과해도 전혀 문제없음
// 출구는 레버를 당기기 전에 지나가는 것만 허용되고, 탈출은
//  반드시 레버를 당긴 이후에 그 칸에 도달했을 때를 의미하므로,
//  탈출 판정은 toLever + toExit 합산 값으로만 별도로 계산한다.
//
// 시간복잡도
// BFS 1회당 O(N*M), 총 2회 수행하므로 O(N*M)
