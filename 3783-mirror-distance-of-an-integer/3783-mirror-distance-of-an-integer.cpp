class Solution {
public:
    int mirrorDistance(int n) {
        int ans = 0;
        string s = to_string(n);
        reverse(s.begin(),s.end());
        ans = abs(n-stoi(s));
        return ans;
    }
};