class Solution {
public:
    int n;
    int t[301][5001];
    int solve(int k, vector<int>& c,int i){
        if(k==0){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(t[i][k]!=-1){
            return t[i][k];
        }
        if(k<c[i]){
            return t[i][k]= solve(k,c,i+1);
        }

        int pick= solve(k-c[i],c,i);
        int skip= solve(k,c,i+1);
        return t[i][k]=pick+skip;
    }
    int change(int k, vector<int>& c) {
         n = c.size();
         memset(t,-1,sizeof(t));
         return solve(k,c,0);
    }
};