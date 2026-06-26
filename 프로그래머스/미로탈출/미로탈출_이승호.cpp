#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool map[101][101];
int sizeX = 0;
int sizeY = 0;

// 우 하 좌 상
int dx[4] = {0,  1,  0, -1};
int dy[4] = {1,  0, -1,  0};

int BFS(pair<int,int> start, pair<int,int> end)
{
    // 첫번째 오류 부분 -> visited랑 parent를 정적 2차원배열로 선언했었는데 제대로 초기화 되지 않았음 -> 그래서 vector를 사용해서 초기화 or size만큼 for문 돌려서 초기화
    vector<vector<bool>> visited(sizeX, vector<bool>(sizeY, false));
    vector<vector<pair<int,int>>> parent(sizeX, vector<pair<int,int>>(sizeY));
    
    
    

    visited[start.first][start.second] = true;
    queue<pair<int, int>> q;

    q.push({ start.first, start.second });
    parent[start.first][start.second] = { start.first, start.second };
    
    // 세번째 오류, while문을 빠져나왔을 때 도달하지 못했을때는 바로 -1 반환 시키기 위한 변수값 
    bool isFound = false;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr.first == end.first and curr.second == end.second)
        {
            isFound = true;
            break;
        }
        

        for (int i = 0; i < 4; ++i)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx < 0 || nx > sizeX - 1 || ny < 0 || ny > sizeY - 1)
                continue;

            if (map[nx][ny])
                continue;

            if (visited[nx][ny])
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            parent[nx][ny] = { curr.first , curr.second };
        }
    }

    if (!isFound) return -1;
    
    int x = end.first;
    int y = end.second;

    vector<pair<int, int>> bfs;
    while (parent[x][y].second != y || parent[x][y].first != x)
    {
        bfs.push_back({ x, y });

        pair<int, int> p = parent[x][y];

        x = p.first;
        y = p.second;
    }

    bfs.push_back({ x, y });

    reverse(bfs.begin(), bfs.end());

    return bfs.size() -1;
}

int solution(vector<string> maps) {
    int answer = 0;

    pair<int, int> lever;
    pair<int, int> start;
    pair<int, int> exit;

    sizeX = maps.size();
    sizeY = maps[0].size();

    for (int i = 0 ; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == 'S')
            {
                start = make_pair(i, j);
            }
            if (maps[i][j] == 'L')
            {
                lever = make_pair(i, j);
            }
            if (maps[i][j] == 'E')
            {
                exit = make_pair(i, j);
            }
            if (maps[i][j] == 'X')
            {
                map[i][j] = true;
            }
        }
    }

    // 시작점에서 레버까지

    int resultsl = BFS(start, lever);
    if (resultsl == -1) // 오류 두번째, resultsl == 0 체크해서 오류 -> BFS 함수에서 size() - 1을 하거나 -1로 반환하기에 -1로 체크
        return -1;

    int resultle = BFS(lever, exit);

    if (resultle == -1)
        return -1;

    // 레버부터 탈출구까지
    answer = resultsl + resultle;


    return answer;
}