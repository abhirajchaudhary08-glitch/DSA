
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string s2="";
            for(int i=0;i<s.size();i=i+k){
                int sum=0;
                for(int j=i; j<s.size() && j<i+k;j++){
                    sum+= s[j]-'0';
                }
                s2+= to_string(sum);
            }
            s=s2;
        }
        return s;
    }
};