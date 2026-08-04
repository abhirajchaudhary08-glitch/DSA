class Solution {
public:
int t[60];

int f(int n) {
    if (t[n] != -1) {
        return t[n];
    }
    
    int bst = 0;
    
    for(int i=1;i<n;i++){
        int rmg = n-i;
        bst =max(bst,i*rmg);
        bst = max(bst,i*f(rmg));
    }
    
    return t[n] = bst;
}

    
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return f(n);
    }
};