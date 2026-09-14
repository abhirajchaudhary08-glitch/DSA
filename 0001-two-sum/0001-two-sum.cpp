// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i;
//         int j;
//         for(i = 0; i<nums.size();i++){
//             for(j= i+1; j<nums.size(); j++)
//             if(nums[j]==target - nums[i]){
//                 return {i,j};
//             }
//         }
//         return {i,j};
        
//     }
    
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0; i<nums.size(); i++){
            int x=target-nums[i];
            if(mp.count(x))
                return {mp[x], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};