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
    // char seen_at[256];
    // std::memset(seen_at, -1, 256);
    std::array<int, 256> seen_at;
    seen_at.fill(-1);
    int maxLen = 0, lastPos = -1, slen = s.size();
    for (int i=0;i<slen;i++) {
      if (seen_at[s[i]] != -1 && lastPos < seen_at[s[i]]) {
        lastPos = seen_at[s[i]];
      }
      if (( i - lastPos ) > maxLen) {
        maxLen = i - lastPos;
      }
      seen_at[s[i]] = i;
    }
    return maxLen;
  }
};