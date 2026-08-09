class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 1. Find the maximum element to size our points array
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        // 2. Accumulate the total points each specific number can yield
        vector<int> points(maxVal + 1, 0);
        for (int num : nums) {
            points[num] += num;
        }

        // 3. Space-optimized Dynamic Programming (House Robber logic)
        // twoBack represents the max score up to (i - 2)
        // oneBack represents the max score up to (i - 1)
        int twoBack = 0;
        int oneBack = points[1]; // 1 <= nums[i] <= 10^4 based on constraints

        for (int i = 2; i <= maxVal; i++) {
            // Core DP step: Choose between skipping 'i' or taking 'i'
            int current = max(oneBack, twoBack + points[i]);
            
            // Shift our variables forward for the next iteration
            twoBack = oneBack;
            oneBack = current;
        }

        // The final answer is the max score accumulated up to maxVal
        return oneBack;
    }
};