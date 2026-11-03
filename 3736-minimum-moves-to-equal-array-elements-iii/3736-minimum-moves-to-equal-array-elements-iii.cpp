class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int last=nums[n-1];

        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=last-nums[i];
        }
        return total;
    }
};