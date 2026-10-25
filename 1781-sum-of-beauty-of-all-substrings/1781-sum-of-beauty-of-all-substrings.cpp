
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                if (mp.size() > 1) {
                    int maxFreq = 0;
                    int minFreq = INT_MAX;

                    for (auto it : mp) {
                        maxFreq = max(maxFreq, it.second);
                        minFreq = min(minFreq, it.second);
                    }

                    total += maxFreq - minFreq;
                }
            }
        }

        return total;
    }
};
