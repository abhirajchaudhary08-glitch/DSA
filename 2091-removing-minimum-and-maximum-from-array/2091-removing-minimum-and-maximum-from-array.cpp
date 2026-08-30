class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mine = INT_MAX;
        int mxe = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mine = min(mine,nums[i]);
            mxe = max(mxe,nums[i]);
        }
        auto it = find(nums.begin(),nums.end(),mine);
        auto x = find(nums.begin(),nums.end(),mxe);

        int ind = distance(nums.begin(), it);
        int indx = distance(nums.begin(), x);

        int lo = min(ind, indx);
        int hi = max(ind, indx);

        int case1 = hi + 1;                // remove both from the front
        int case2 = n - lo;                 // remove both from the back
        int case3 = (lo + 1) + (n - hi);    // split: front + back

        return min({case1, case2, case3});
    }
};