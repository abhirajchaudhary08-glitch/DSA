//       string s = "";
// int ct = 0;
// for(int x : nums) {
//     s += to_string(x);
// }
// // 2. Convert integer d to character (if d is an int)
// char targetChar = d + '0'; 
// for(int i = 0; i < s.length(); i++){
//     if(s[i] == targetChar){
//         ct++;
//     }
// }

// return ct;
    class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count=0;

        for(int n:nums){
            while(n){
                int r=n%10;
                n/=10;
                if(r==digit)    count++;
            }
        }
        return count;
    }
};
    
