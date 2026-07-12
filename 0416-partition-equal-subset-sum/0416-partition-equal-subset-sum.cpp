class Solution {
public:
    bool f(int index,int remaining,vector<int>& nums,vector<vector<int>>& dp){
        if(remaining == 0) return true;
        if(index == nums.size()) return false;
        
        if(dp[index][remaining]!= -1){
           return dp[index][remaining];
        }
        bool pick = false;
        if(nums[index]<=remaining){
            pick = f(index+1,remaining-nums[index],nums,dp);
        }
        bool notpick = f(index+1,remaining,nums,dp);
        return dp[index][remaining] = pick or notpick;
       
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
            int k = sum/2;
            vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
            return f(0,k,nums,dp);

    }
};