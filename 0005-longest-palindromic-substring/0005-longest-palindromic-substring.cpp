class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        if (n == 0) return "";

        int rleft = 0;
        int rright = 0;
        int curMax = 1;

        for (int i = 0; i < 2 * n - 1; i++) {

            int l = i / 2;
            int r = (i % 2 == 0) ? l : l + 1;
            if (s[l] != s[r]) continue;
            while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }

            int length = r - l + 1;

            if (length > curMax) {
                curMax = length;
                rleft = l;
                rright = r;
            }
        }

        return s.substr(rleft, curMax);
    }
};