#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void cleanMaxQueue(priority_queue<pair<int, int>>& max_pq, unordered_map<int, bool>& is_alive)
{
    while (!max_pq.empty() && !is_alive[max_pq.top().second])
    {
        max_pq.pop();
    }
}

void cleanMinQueue(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min_pq, unordered_map<int, bool>& is_alive) 
{
    while (!min_pq.empty() && !is_alive[min_pq.top().second])
    {
        min_pq.pop();
    }
}

vector<int> solution(vector<string> operations) 
{
    vector<int> answer;

    priority_queue<pair<int, int>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_greater;

    unordered_map<int, bool> alive;
    int id = 0;

    for (int i = 0; i < operations.size(); ++i)
    {
        int num = stoi(operations[i].substr(2));



        // 숫자 추가
        if (operations[i][0] == 'I')
        {
            pq.push({ num, id });
            pq_greater.push({ num, id });
            alive[id] = true;
            id++;
        }
        // 최솟값 최댓값 삭제
        else if ((operations[i][0] == 'D'))
        {
            // 최댓값 삭제
            if (num == 1)
            {
                cleanMaxQueue(pq, alive);
                if (pq.empty())
                    continue;

                alive[pq.top().second] = false;
                pq.pop();
            }
            // 최솟값 삭제
            else if (num == -1)
            {
                cleanMinQueue(pq_greater, alive);
                if (pq_greater.empty())
                    continue;

                alive[pq_greater.top().second] = false;
                pq_greater.pop();
            }
        }
    }

    cleanMaxQueue(pq, alive);
    cleanMinQueue(pq_greater, alive);

    //if (pq.empty() && pq_greater.empty()) 
    //{
    //    return { 0, 0 };
    //}
    //else if(pq.empty() || pq_greater.empty())
    //{
    //    if (pq.empty())
    //    {
    //        return {0, pq_greater.top().first};
    //    }
    //    else if (pq_greater.empty())
    //    {
    //        return {pq.top().first, 0};
    //    }
    //}
    //else
    //{
    //    return { pq.top().first, pq_greater.top().first };
    //}

    // 만약에 큐에 한개만 남아있어도 0,0을 반환?
    if (pq.empty() || pq_greater.empty()) 
    {
        return { 0, 0 };
    }
    else
    {
        return { pq.top().first, pq_greater.top().first };
    }
}