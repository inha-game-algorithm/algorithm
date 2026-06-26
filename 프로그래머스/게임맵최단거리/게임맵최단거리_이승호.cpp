#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> maps)
{
    int sizeY = maps.size();
    int sizeX = maps[0].size();

    // dist 배열을 -1로 초기화 (방문하지 않음의 의미) // 비용배열을 추가로 만들었다가 그냥 맵에서 값을 변경하는 방식으로 변경
    //vector<vector<int>> dist(sizeY, vector<int>(sizeX, -1));

    //int dist[101][101] = { INT_MAX };

    // queue를 pair로 사용안하고 int로 1차원개념으로 수정
    //queue<pair<int, int>> q;
    queue<int> q;

    q.push(0);
    //dist[0][0] = 1; // 시작 칸을 포함하므로 1부터 시작

    while (!q.empty())
    {
        int curr = q.front();
        //int y = q.front().first;
        //int x = q.front().second;

        int y = curr / sizeX;
        int x = curr % sizeX;

        q.pop();

        // 끝지점이라면 그냥 바로 탈출
        if (y == sizeY - 1 && x == sizeX - 1)
            return maps[y][x];


        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 1. 맵 범위 확인
            if (ny < 0 || ny >= sizeY || nx < 0 || nx >= sizeX)
                continue;

            // 2. 벽(0)이면 패스
            //if (maps[ny][nx] == 0)
            //    continue;

            // 3. 이미 방문한 적이 있다면(값이 -1이 아니라면) 패스
            //if (dist[ny][nx] != -1)
            //    continue;
            
            // maps에서 값을 변경함으로 2번 3번을 합쳐서 체크
            // 벽이거나 이미 지나가서 값이 바뀌었거나
            if (maps[ny][nx] != 1)
                continue;

            
            //dist[ny][nx] = dist[y][x] + 1;
            maps[ny][nx] = maps[y][x] + 1;
            q.push(ny * sizeX + nx);
        }
    }

    끝지점 도착못하고 탈출했으면 -1 반환
    return -1;
}