class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](unsigned char c) { return !isalnum(c); });
       for (char &c : s) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
        int n = s.length();
        int i=0;
        int j= n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
};