class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =nums.size();
        int mini= *min_element(nums.begin(), nums.end());
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i]-mini;
        }
        return total;
    }
};