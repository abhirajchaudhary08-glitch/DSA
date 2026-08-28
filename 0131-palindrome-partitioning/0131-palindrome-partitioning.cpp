class Solution {
public:
    vector<vector<string>> res;
   bool pal(string s,int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
   }
    void f(string s,int i,int n, vector<string>&v){
        if(i==n){
            res.push_back(v);
            return;
        }
        for(int k=i;k<n;k++){
            if(pal(s,i,k)){
                v.push_back(s.substr(i, k - i + 1));
                f(s,k+1,n,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size()==1)
            return{{s}};
            vector<string> v;
            f(s,0,s.size(),v);
            return res;
    }

};