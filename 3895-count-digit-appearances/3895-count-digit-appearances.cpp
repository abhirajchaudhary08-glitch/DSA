class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int d) {
      string s = "";
int ct = 0;

// 1. Build the string
for(int x : nums) {
    s += to_string(x);
}

// 2. Convert integer d to character (if d is an int)
char targetChar = d + '0'; 

// 3. Count occurrences
for(int i = 0; i < s.length(); i++){
    if(s[i] == targetChar){
        ct++;
    }
}

return ct;
    }
};