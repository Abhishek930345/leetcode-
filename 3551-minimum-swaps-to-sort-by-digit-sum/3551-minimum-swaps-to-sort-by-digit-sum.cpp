// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n=nums.size();

//         int total=0;

//         vector<int> arr;
//         for(int i =0;i<n;i++){
//             int num = nums[i];
//             int sum=0;
//             while(num>0){
//                 int k = num%10;
//                 sum+=k;
//                 num=num/10;
//             }
//             arr.push_back(sum);
//         }
//         for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;

//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//                 total++;
//             }
//         }

//         swap(arr[i], arr[minIndex]);

//     }

//       return total;
//     }
// };

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                int k = num % 10;
                sum += k;
                num /= 10;
            }

            arr.push_back({sum, nums[i]});
        }

        vector<pair<int, int>> sorted = arr;

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[sorted[i].second] = i;
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            while (arr[i].second != sorted[i].second) {
                int j = pos[arr[i].second];

                swap(arr[i], arr[j]);
                total++;
            }
        }

        return total;
    }
};