class Solution {
public:
    long long waysToBuyPensPencils(int t, int c1, int c2) {
       long long ans = 0;
       for(int i=0;i*c1<=t;i++){
        ans+=(t-i*c1)/c2+1;
       }
       return ans;
    }
};