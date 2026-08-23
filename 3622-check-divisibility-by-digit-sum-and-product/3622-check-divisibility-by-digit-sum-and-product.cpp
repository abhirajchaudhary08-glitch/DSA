class Solution {
public:
    bool checkDivisibility(int n) {
        int on = n;
        int sm = 0;
        int psm = 1;
        while(n>0){
            sm+=n%10;
            psm*=n%10;
            n/=10;
        }
        int v = sm+psm;
        if(on%v==0){
            return true;
        }
        return false;
    }
};