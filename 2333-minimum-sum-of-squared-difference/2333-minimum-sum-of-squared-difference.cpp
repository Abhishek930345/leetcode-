// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         int n = nums1.size();

//         priority_queue<int> pq;

//         for (int i = 0; i < n; i++) {
//             pq.push(abs(nums1[i] - nums2[i]));
//         }

//         long long k = (long long)k1 + k2;

//         while (k > 0 && !pq.empty()) {
//             int h = pq.top();
//             pq.pop();

//             if (h == 0) {
//                 pq.push(h);
//                 break;
//             }

//             h--;
//             pq.push(h);
//             k--;
//         }

//         long long sum = 0;

//         while (!pq.empty()) {
//             long long sq = pq.top();
//             sum += sq * sq;
//             pq.pop();
//         }

//         return sum;
//     }
// };


class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int mx = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            if (d > low) {
                used += d - low;
                d = low;
            }
            ans += 1LL * d * d;
        }

        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= low && diff[i] > 0) {
                ans -= 1LL * low * low;
                ans += 1LL * (low - 1) * (low - 1);
                remaining--;
            }
        }

        return ans;
    }
};