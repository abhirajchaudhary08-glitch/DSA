class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                st.pop();
               // i++;
            }else{
                st.push(s[i]);
            }
        }
        string p = "";
        while(!st.empty()){
            p+=st.top();
            st.pop();
        }
        reverse(p.begin(),p.end());
        return p;
    }
};