class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        long long small = 0;
        long long big = 0;

        for (int i = 0; i < n; i++) {
            arr.push_back(abs(nums[i]));
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                small += 1LL * arr[i] * arr[i];
            } else {
                big += 1LL * arr[i] * arr[i];
            }
        }

        return big - small;
    }
};