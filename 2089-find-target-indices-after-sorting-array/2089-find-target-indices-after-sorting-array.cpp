class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        vector<int> p;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==t){
            p.push_back(i);
            }
        }
        return p;
    }
};