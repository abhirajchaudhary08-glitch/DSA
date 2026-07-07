class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxR = 0;
        for(int i = 0;i<nums.size();i++){
            if(i>mxR) return false;
            mxR = max(mxR,i+nums[i]);
        }
        return true;
    }
};