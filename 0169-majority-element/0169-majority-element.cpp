class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }
            else if(el!=nums[i]) cnt--;

            else cnt++;
        }

        int maxele = 0;
       for(int i = 0; i < n; i++) {
            if(nums[i] == el)
                maxele++;
        }

        if(n / 2 <= maxele)
            return el;

        return -1;
        
    }
};