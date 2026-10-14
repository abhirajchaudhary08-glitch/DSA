class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n =arr.size();
        int i=0;
        int j=0;
        int currSum=0;
        vector<int> minBstlenidx(n,INT_MAX);
        int bestMinlen = INT_MAX;
        int res = INT_MAX;
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target){
                currSum-=arr[i++];
            }
            if(currSum==target){
                int len = j-i+1;
                if(i>0 && minBstlenidx[i-1]!=INT_MAX){
                res=min(res,len+minBstlenidx[i-1]);
                }
               bestMinlen=min(bestMinlen,len); 
            }
            minBstlenidx[j] = bestMinlen;
            j++;
        }
        return res == INT_MAX ? -1 : res;
    }
};