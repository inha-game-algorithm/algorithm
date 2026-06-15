class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for (auto num : nums)
        {
            if (num % 2 == 0) result.insert(result.begin(), num);
            else result.push_back(num);
        }
        return result;
    }
};