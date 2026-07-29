class Solution {
public:
    int t[302][12];
    int f(vector<int> &jd,int idx,int n,int d){
        if(d==1){
            int mxD = jd[idx];
            for(int i=idx;i<n;i++){
                mxD = max(mxD,jd[i]);
            }
            return mxD;
        }
        if(t[idx][d]!=-1) return t[idx][d];
        int mxD = jd[idx];
        int finalresult=INT_MAX;
        for(int i=idx;i<=n-d;i++){
            mxD = max(mxD,jd[i]);
            int result = mxD+f(jd,i+1,n,d-1);
            finalresult = min(finalresult,result);
        }
        return t[idx][d]=finalresult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n =jd.size();
        if(n<d) return -1;
        memset(t,-1,sizeof(t));
        return f(jd,0,n,d);
    }
};