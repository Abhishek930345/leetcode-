// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size();
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=arr[j];
//                 if(sum%2!=0) cnt++;
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;

        long long even = 1, odd = 0;
        long long sum = 0, cnt = 0;

        for(int x : arr) {
            sum += x;

            if(sum % 2 == 0) {
                cnt = (cnt + odd) % mod;
                even++;
            }
            else {
                cnt = (cnt + even) % mod;
                odd++;
            }
        }

        return cnt;
    }
};