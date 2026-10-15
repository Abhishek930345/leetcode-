class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        map<int, int> mp;
        int s = 0;

        for (int i = 0; i < n; i++) {
            mp.clear(); 

            for (int j = i; j < n; j++) {
                if (mp.find(nums[j]) == mp.end()) {
                    cnt++;
                    mp[nums[j]]++;
                } else {
                    mp[nums[j]]++;
                }

                s = s + (cnt * cnt);
            }

            cnt = 0;
        }

        return s;
    }
};