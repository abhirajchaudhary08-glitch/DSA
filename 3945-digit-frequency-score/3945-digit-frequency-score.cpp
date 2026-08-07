class Solution {
public:
    int digitFrequencyScore(int n) {
    
      int sm = 0;

// Start with temp = n. 
// Keep going as long as temp > 0. 
// Divide temp by 10 at the end of every loop.
for(int temp = n; temp > 0; temp /= 10) {
    sm += (temp % 10);
}
return sm;
    }
};