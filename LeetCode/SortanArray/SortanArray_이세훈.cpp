class Solution {
public:
    void mergeSort(vector<int>& nums, int left, int mid, int right) {
        std::vector<int> arr;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                arr.push_back(nums[i]);
                ++i;
            }
            else {
                arr.push_back(nums[j]);
                ++j;
            }
        }

        while (i <= mid) {
            arr.push_back(nums[i]);
            ++i;
        }

        while (j <= right) {
            arr.push_back(nums[j]);
            ++j;
        }

        for (int k = left; k <= right; ++k) {
            nums[k] = arr[k - left];
        }
    }

    void merge(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            merge(nums, left, mid);
            merge(nums, mid + 1, right);
            mergeSort(nums, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        merge(nums, 0, nums.size() - 1);

        return nums;
    }
};