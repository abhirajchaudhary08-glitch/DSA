class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto it = find(nums.begin(),nums.end(),target);
        if(it!=nums.end()){
            int idx = distance(nums.begin(),it);
            ans.push_back(idx);
        }else{
            ans.push_back(-1);
        }
        auto rit = find(nums.rbegin(), nums.rend(), target);
    if (rit != nums.rend()) {
        int index = (nums.rend() - 1) - rit;
        ans.push_back(index);
    }else{
           ans.push_back(-1);
        }

     return ans;
    }
};