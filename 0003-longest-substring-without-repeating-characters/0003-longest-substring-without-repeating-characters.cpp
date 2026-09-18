// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int ct = 0;
//         int maxct = 0;
//         string p = "";
        
//         for(int i = 0; i < s.length(); i++) {
//             if(p.find(s[i]) == string::npos) {
//                 p.push_back(s[i]);  
//                 ct++; 
//             } 
//             else {
//                 size_t foundPos = p.find(s[i]);
//                 // Remove everything from the start up to and including that duplicate
//                 p.erase(0, foundPos + 1);
//                 p.push_back(s[i]);
//                 ct = p.length();
//             }
//             maxct = max(maxct, ct);
//         }
//         return maxct;
//     }
// };
 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            // This vector tracks visited characters for the substring starting at 'i'.
            // It is reset for each new starting position.
            vector<bool> vis(128, false); // Using 128 for full ASCII support
            for (int j = i; j < n; j++) {
                // If the current character has already been seen in this substring
                if (vis[s[j]]) {
                    break;
                }
                // Otherwise, update the result and mark the character as seen
                else {
                    res = max(res, j - i + 1);
                    vis[s[j]] = true;
                }
            }
        }
        return res;
    }
};