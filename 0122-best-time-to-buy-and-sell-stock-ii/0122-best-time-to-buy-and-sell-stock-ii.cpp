class Solution {
public:
    // int f(vector<int>& nums,int i,int j){
    //     int n = nums.size();
    //     if(nums[j]>nums[i]){
    //         return 0;
    //     }
    //     vector<int> t(n+1,0);
    //     for(int i=0;i<n;i++){
    //         int j = i+1;
            
    //         if(nums[j]>nums[i]){
    //             int prof = abs(nums[i]-nums[j]);
    //             dp[i] = max(dp[i],prof);
    //         }else{
    //             int prof = abs(nums[i]-nums[j]);
    //             dp[i] = max(dp[j],prof);
    //         }
    //     }
    // }
    int maxProfit(vector<int>& nums) {
        
        int n = nums.size();
        int prof = 0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                prof+=(nums[i]-nums[i-1]);
            }
        }
        return prof;
    }
};