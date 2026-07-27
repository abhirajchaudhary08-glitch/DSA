class Solution {
public:
    vector<int> dp;

    int solve(int n){
        if(n==0) return 0;
        if(n==1) return 0;   // No cost to split 1 into 1.

        if(dp[n]!=-1)
            return dp[n];

        int cost;

        if(n%2==0){
            int a = n/2;
            cost = a*a + 2*solve(a);
        }
        else{
            int a = (n-1)/2;
            int b = (n+1)/2;
            cost = a*b + solve(a) + solve(b);
        }

        return dp[n] = cost;
    }

    int minCost(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};