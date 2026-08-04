class Solution {
public:
        int t[102];
        int f(int i,string &s,int &n){
            if(t[i]!=-1){
                return t[i];
            }
            if(i==n){
                return t[i]=1;
            }
            if(s[i] =='0'){
                return t[i]=0;
            }
            int ony_ith_ch = f(i+1,s,n);
            int ith_i_plus_1_char = 0;
            if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' and s[i+1]<='6'))
            ith_i_plus_1_char = f(i+2,s,n);
            }
            return t[i]=ony_ith_ch + ith_i_plus_1_char;
        }
    int numDecodings(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return f(0,s,n);
    }
};