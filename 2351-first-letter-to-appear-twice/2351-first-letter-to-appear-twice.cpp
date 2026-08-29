class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        for(auto &it : s){
            if(st.count(it)>0){
                return it;
            }
            st.insert(it);
        }
       return ' ';
    }
};