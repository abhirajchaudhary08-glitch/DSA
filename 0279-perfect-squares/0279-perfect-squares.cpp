#include <cmath>

class Solution {
public:
    int numSquares(int n) {
    //     // 1. Check if it's 1
    //     if (isPerfectSquare(n)) {
    //         return 1;
    //     }
        
    //     // 2. Check if it's 4 using Legendre's Theorem: n = 4^a(8b + 7)
    //     int temp = n;
    //     while (temp % 4 == 0) {
    //         temp /= 4; // Divide out all the 4s
    //     }
    //     if (temp % 8 == 7) {
    //         return 4;
    //     }
        
    //     // 3. Check if it's 2
    //     for (int i = 1; i * i <= n; i++) {
    //         if (isPerfectSquare(n - (i * i))) {
    //             return 2;
    //         }
    //     }
        
    //     // 4. By elimination, it must be 3
    //     return 3;
    vector<int> dp(n+1,1);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = i;
    }
    if(dp[n]!=n){
        return dp[n];
    }
    for(int i=1;i<=n;i++){
        int p = sqrt(i);
        for(int j=1;j<=p;j++){
            dp[i] = min(dp[i],1+dp[i-(j*j)]);
        }
    }
    return dp[n];
    }
};