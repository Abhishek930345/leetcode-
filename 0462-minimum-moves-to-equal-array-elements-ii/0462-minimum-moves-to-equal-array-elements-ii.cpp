
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = n / 2;
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += abs(nums[mid] - nums[i]);
        }

        return total;
    }
};
