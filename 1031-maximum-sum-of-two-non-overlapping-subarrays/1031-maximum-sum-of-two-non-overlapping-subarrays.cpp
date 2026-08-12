class Solution {
public:
    int solve(vector<int>& prfs, int f, int s){
        int n = prfs.size();
        int mlss = 0;
        int ans = 0;
        for(int i = f + s - 1; i < n; i++){
            int lend = i - s;
            int lstprv = lend - f;
            int sblocksum = prfs[i] - prfs[lend];
            int fblocksm = prfs[lend] - (lstprv < 0 ? 0 : prfs[lstprv]);
            
            mlss = max(mlss, fblocksm);
            ans = max(ans, mlss + sblocksum);
        }
        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n = nums.size();
        vector<int> prfs(n, 0);
        prfs[0] = nums[0];
        
        // FIX 1: Start loop from 1 to avoid accessing prfs[-1]
        for(int i = 1; i < n; i++){ 
            prfs[i] = prfs[i-1] + nums[i];
        }
        
        // FIX 2: Pass 'prfs' instead of 'nums' to the solve function
        return max(solve(prfs, f, s), solve(prfs, s, f));
    }
};