class Solution {
public:
    int countCommas(int n) {
        int ct = 0;
        if(n>999){
            ct = n-999;
        }
        return ct;
    }
};