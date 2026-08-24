class Solution {
public:
    vector<string> ans;
    vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string &digits,string &temp,int ind){
        int n = digits.size();
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        int crr_nm = digits[ind]-'0';
        for(auto &key : keys[crr_nm]){
            temp.push_back(key);
            solve(digits,temp,ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return ans;
        }
        string temp;
        solve(digits,temp,0);
        return ans;
    }
};