class Solution {
    vector<int> dp;

    int ftd(const vector<int>& arr, int i, int end) {
        // Base cases for the boundaries
        if (i > end) return 0;
        if (i == end) return arr[i];
        
        // Memoization check
        if (dp[i] != -1) return dp[i];
        
        // Recursive step: Rob current + jump 2, or skip current + jump 1
        return dp[i] = max(arr[i] + ftd(arr, i + 2, end), ftd(arr, i + 1, end));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Scenario 1: Exclude the last house (0 to n-2)
        dp.assign(n, -1);
        int option1 = ftd(nums, 0, n - 2);
        
        // Scenario 2: Exclude the first house (1 to n-1)
        dp.assign(n, -1);
        int option2 = ftd(nums, 1, n - 1);
        
        return max(option1, option2);
    }
};