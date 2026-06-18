#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int count = 0;
     multiset<int> ms(scoville.begin(), scoville.end());
    
    while (*ms.begin() < K) 
    {
        if (ms.size() < 2)
            return -1;
        auto itFirst = ms.begin();
        auto itSecond = std::next(ms.begin());
        int i[2] = {*itFirst, *itSecond};
        ms.erase(itFirst);
        ms.erase(itSecond);
        ms.insert(i[0] + i[1] * 2);
        ++count;
    }
    
    return count;
}
