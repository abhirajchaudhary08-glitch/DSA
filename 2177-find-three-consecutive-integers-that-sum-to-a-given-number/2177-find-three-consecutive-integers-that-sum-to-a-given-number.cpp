class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        long long p = num/3;
        if(num%3==0){
            ans.push_back(p-1);
            ans.push_back(p);
            ans.push_back(p+1);
        }
        return ans;
    }
};