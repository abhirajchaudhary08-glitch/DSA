class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = n;
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>=target){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }        
                    
            }
            return ans;

    }
};