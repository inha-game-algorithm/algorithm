#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int x;
    int y;
};

int bfs(Pos start, Pos target, const vector<string>& maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    Pos dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    queue<Pos> q;
    
    // 시작점 세팅
    q.push(start);
    dist[start.y][start.x] = 0;
    
    while (!q.empty()) {
        Pos current = q.front();
        q.pop();
        
        // 조기 탈출
        if (current.x == target.x && current.y == target.y) {
            return dist[current.y][current.x];
        }
        
        // 4방향 탐색
        for (int i = 0; i < 4; ++i) {

            // 다음 탐색지를 넣고
            int nextX = current.x + dir[i].x;
            int nextY = current.y + dir[i].y;
            
            // 아래 조건에 부합하면 for 1tic pass
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
            
            // 초기화 값 -1이 아니고, 벽도 아니면 dist값 증가 시키고 큐에 푸시.
            if (dist[nextY][nextX] == -1 && maps[nextY][nextX] != 'X') {
                dist[nextY][nextX] = dist[current.y][current.x] + 1;
                q.push({nextX, nextY});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    Pos start, lever, exit;
    
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (maps[y][x] == 'S') start = {x, y};
            else if (maps[y][x] == 'L') lever = {x, y};
            else if (maps[y][x] == 'E') exit = {x, y};
        }
    }
    
    // 시작위치, 찾을 대상, 맵
    int findLever = bfs(start, lever, maps);
    if (findLever == -1) return -1; 
    
    int findExit = bfs(lever, exit, maps);
    if (findExit == -1) return -1; 
    
    return findLever + findExit;
}