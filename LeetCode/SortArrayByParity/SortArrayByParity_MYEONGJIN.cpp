#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        vector<int> a(nums);
        vector<int> r;

        vector<int>::iterator it;

        do
        {
            it = find_if(a.begin(), a.end(), [](int i) { return (i % 2) == 0; });
        
            if (it != a.end())
            {
                r.push_back(*it);
                it = a.erase(it);
            }
        } while (it != a.end());

        r.insert(r.end(), a.begin(), a.end());

        return r;
    }
};


