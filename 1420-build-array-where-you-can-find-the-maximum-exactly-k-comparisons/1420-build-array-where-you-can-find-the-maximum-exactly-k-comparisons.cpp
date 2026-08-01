class Solution {
public:
    int N,M,K;
    int MOD = 1e9+7;
    int t[51][51][101];
    int f(int idx, int searchcost, int mxsofar){
        if(idx==N){
            if(searchcost == K){
                return 1;
            }
            return 0;
        }
        if(t[idx][searchcost][mxsofar]!=-1){
            return t[idx][searchcost][mxsofar];
        }
        int res = 0;
        for(int i=1;i<=M;i++){
            if(i>mxsofar){
                res=(res+f(idx+1,searchcost+1,i))%MOD;
            }else{
                res=(res+f(idx+1,searchcost,mxsofar))%MOD;
            }
        }
        return t[idx][searchcost][mxsofar]=res%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t,-1,sizeof(t));
        return f(0,0,0);
    }
};