class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int dp[301][301] = {0}, res = 0;
        for(int i = 0 , n = nums.size(); i < n; ++i){
            int num = nums[i];
            for(int diff = 299; diff >= 0; --diff){
                int L = 0, R = 0;
                if(num + diff < 301) L = dp[num + diff][diff];
                if(num - diff > 0) R = dp[num - diff][diff];
                dp[num][diff] = max(dp[num][diff + 1] , 1 + max(L , R));
                res = max(res , dp[num][diff]);
            }
        }
        return res;
    }
};