class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(t1[i-1]==t2[j-1]){
                    t[i][j] = t[i-1][j-1]+1;
                }
                t[i][j] = max(t[i][j],t[i-1][j]);
                t[i][j] = max(t[i][j],t[i][j-1]);
            }
        }
        return t[n][m];
    }
};