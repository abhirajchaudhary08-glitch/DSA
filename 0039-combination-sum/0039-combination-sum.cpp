#define ll long long
class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,vector<int>& v,ll sm,int target,vector<int> res){
        if(i==n){
            if(sm==target){
                ans.push_back(res);
            }
            return;
        }
        f(i+1,n,v,sm,target,res);
        res.push_back(v[i]);
        if(sm+v[i]<=target)
        f(i,n,v,sm+v[i],target,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        f(0,candidates.size(),candidates,0ll,target,res);
        return ans;
    }
};