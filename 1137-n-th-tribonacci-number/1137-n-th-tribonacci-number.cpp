class Solution {
public:
    int t[50];
    int f(int n){
        if(n==0) return 0;
        if(n==1 || n==2){
            return 1;
        }
        if(t[n]!=-1){
            return t[n];
        }
        return t[n] = f(n-1)+f(n-2)+f(n-3);
    }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t));
        return f(n);
    }
};