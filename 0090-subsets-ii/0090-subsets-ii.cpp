class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int>& temp,vector<int>& nums, int pos){
        res.push_back(temp);
        for(int i=pos;i<nums.size();i++){
            if(i!=pos and nums[i]==nums[i-1]) continue;
                temp.push_back(nums[i]);
                solve(res,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(res,temp,nums,0);
        return res;
    }
};