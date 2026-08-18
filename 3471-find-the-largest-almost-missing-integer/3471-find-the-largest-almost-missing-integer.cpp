class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        // Sliding window
        for (int i = 0; i <= n - k; i++) {

            // Store distinct elements of current window
            unordered_set<int> present;

            for (int j = i; j < i + k; j++) {
                present.insert(nums[j]);
            }

            // Each element gets counted once for this window
            for (int x : present) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Find largest element appearing in exactly one window
        for (auto &[x, count] : freq) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};