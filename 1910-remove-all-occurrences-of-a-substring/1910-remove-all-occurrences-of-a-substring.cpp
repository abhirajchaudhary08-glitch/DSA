// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         size_t it = s.find(part);
//         while (it != std::string::npos) {
//             s.erase(it, part.length());
//             size_t start = (it >= part.length() - 1) ? it - (part.length() - 1) : 0;//imp
//             it = s.find(part, start);
//         }
//         return s;
//     }
// };
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()) {
            s.erase(s.find(part),part.length());
        }
  return s;
    }
};