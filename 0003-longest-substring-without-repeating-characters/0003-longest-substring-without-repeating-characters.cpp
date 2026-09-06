class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ct = 0;
        int maxct = 0;
        string p = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(p.find(s[i]) == string::npos) {
                p.push_back(s[i]);  
                ct++; 
            } 
            else {
                size_t foundPos = p.find(s[i]);
                // Remove everything from the start up to and including that duplicate
                p.erase(0, foundPos + 1);
                p.push_back(s[i]);
                ct = p.length();
            }
            maxct = max(maxct, ct);
        }
        return maxct;
    }
};