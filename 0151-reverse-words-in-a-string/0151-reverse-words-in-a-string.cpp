class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;

        for (char c : s) {
            if (c != ' ') {
                word += c;                 // build current word
            } else if (!word.empty()) {
                st.push(word);             // word just ended
                word.clear();
            }
        }
        if (!word.empty()) st.push(word);  // last word (no trailing space)

        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += ' ';   // no trailing space
        }
        return res;
    }
};