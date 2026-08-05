// class Solution {
// public:
//     bool isSubsequence(string s, string p) {
//        int n = s.length();
//        string t = "";
//        int last_pos = 0; // Track where to start searching in 'p'
       
//        for(int i = 0; i < n; i++) {
//            // Prevent out-of-bounds if last_pos exceeds p's length
//            if (last_pos > p.length()) break;
           
//            // Search for s[i] starting from the character AFTER the last match
//            auto it = find(p.begin() + last_pos, p.end(), s[i]);
           
//            if(it != p.end()) {
//                t.push_back(*it);
//                // Update last_pos to the index right after the found character
//                last_pos = distance(p.begin(), it) + 1;
//            } else {
//                // If a character isn't found, it's impossible to form the subsequence
//                break; 
//            }
//        }
       
//        if(t == s){
//            return true;
//        }
       
//        return false;
//     }
// };
// class Solution {
// public:
//     bool isSubsequence(string s, string p) {
//         int i = 0; // Pointer for s
//         int j = 0; // Pointer for p
        
//         // Traverse both strings
//         while (i < s.length() && j < p.length()) {
//             if (s[i] == p[j]) {
//                 i++; // Character matched, move to the next char in s
//             }
//             j++; // Always move to the next char in p
//         }
        
//         // If we successfully traversed all of s, it is a subsequence
//         return i == s.length();
//     }
// };
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isSubsequence(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        // Create a 2D DP table initialized to 0
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1]) {
                    // Match found: add 1 to the previous diagonal
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // No match: take the max of skipping a char in 's' or 'p'
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // If the length of the LCS equals the length of 's', it's a subsequence
        return dp[n][m] == n;
    }
};