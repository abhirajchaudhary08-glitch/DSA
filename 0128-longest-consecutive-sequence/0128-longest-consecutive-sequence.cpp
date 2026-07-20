class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int csq =1;
        int lsq =0;
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    csq++;
                }else{
                lsq = max(csq,lsq);
                csq = 1;
            }
        }
    }
        return max(lsq,csq);

    }
};