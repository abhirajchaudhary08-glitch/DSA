// #define ll long long
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void f(int i,int n,vector<int>& v,ll sm,int target,vector<int> res){
//         if(i==n){
//             if(sm==target){
//                 ans.push_back(res);
//             }
//             return;
//         }
//         f(i+1,n,v,sm,target,res);
//         res.push_back(v[i]);
//         if(sm+v[i]<=target)
//         f(i,n,v,sm+v[i],target,res);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> res;
//         f(0,candidates.size(),candidates,0ll,target,res);
//         return ans;
//     }
// };
class Solution {
private:
    void findCombination(int idx, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &vis) {
        if(idx == arr.size()) {
            if(!target) ans.push_back(vis);
                
            return;
        }

        if(arr[idx] <= target) { // take
            vis.push_back(arr[idx]);
            findCombination(idx, arr, target - arr[idx], ans, vis);
            vis.pop_back();
        }

        findCombination(idx+1, arr, target, ans, vis);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vis;

        findCombination(0, candidates, target, ans, vis);

        return ans;
    }
};