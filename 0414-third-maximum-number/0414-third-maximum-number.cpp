class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        if(nums.size()>2){
            return nums[nums.size()-3];
        }else{
            return nums[nums.size()-1];
        }
    }
};