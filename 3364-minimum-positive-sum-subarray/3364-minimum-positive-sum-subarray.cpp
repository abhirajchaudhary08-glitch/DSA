// class Solution {
// public:
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         int n = nums.size();
//         int ans = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 int len = j - i + 1;
//                 if (len >= l && len <= r && sum > 0) {
//                     ans = min(ans, sum);
//                 }
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int best = INT_MAX;
        int n = nums.size();
        for(int i = 0; i <= n - l; i++) {
            int sum = 0;
            for(int j = i; j < n && j < i + l; j++) {
                sum += nums[j];
            }
            if (sum > 0) {
                best = min(best, sum);
            }
            for(int j = i + l; j < n && j < i + r; j++) {
                sum += nums[j];
                if (sum > 0) {
                    best = min(best, sum);
                }
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};

