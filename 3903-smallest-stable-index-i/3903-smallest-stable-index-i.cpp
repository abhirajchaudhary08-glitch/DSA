// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int maxValue = nums[i], minValue = nums[i];
//             for (int j = 0; j < i; ++j) {
//                 maxValue = max(maxValue, nums[j]);
//             }
//             for (int j = i + 1; j < n; ++j) {
//                 minValue = min(minValue, nums[j]);
//             }
//             if (maxValue - minValue <= k) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    inline static int suf[100];
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        suf[n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);        

        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (maxSoFar - suf[i] <= k)
                return i;
        }

        return -1;
    }
};