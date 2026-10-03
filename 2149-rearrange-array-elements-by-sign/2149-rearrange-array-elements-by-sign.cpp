class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        int left=0;
        int right=1;
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                arr[left]=nums[i];
                left+=2;
            }
            else {
                arr[right]=nums[i];
                right+=2;
            }
        }
        return arr;
    }
};