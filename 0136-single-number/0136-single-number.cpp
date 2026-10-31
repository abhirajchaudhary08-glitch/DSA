// class Solution {
// public:
//     int singleNumber(vector<int>& nums) { 
//        unordered_map<int,int> a;
// 	   for(auto x: nums)
// 		   a[x]++;
// 	   for(auto z:a)
// 		   if(z.second==1)
// 			   return z.first;
// 	   return -1;
//     }
// };
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int& i: nums) {
            result ^= i;
        }
        return result;
    }
};