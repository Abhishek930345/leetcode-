class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int arr[26];

        for (int i = 0; i < 26; i++) {
            arr[i] = 26 - i;
        }

        int sum = 0;

        for (int i = 0; i < n; i++) {
            int m = arr[s[i] - 'a'];
            sum += m * (i + 1);
        }

        return sum;
    }
};