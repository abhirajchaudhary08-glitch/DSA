class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if(n&1){
            return ans;
        }
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0){
                continue;
            }
            mp[nums[i]]--;
            if(mp[nums[i]*2]==0){
                vector<int> et;
                return et;
            }else{
                mp[nums[i]*2]--;
            }
            ans.push_back(nums[i]);
        }
        return ans;
    }
};