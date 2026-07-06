class Solution {
public:
    
    
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
    if (n == 0) return 0;
    
    double prefix = 1;
    double suffix = 1;
    double max_prod = nums[0];
    
    for (int i = 0; i < n; i++) {
        // If prefix or suffix becomes 0, reset to 1
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;
        
        prefix *= nums[i];
        suffix *= nums[n - 1 - i];
        
        max_prod = max({max_prod, prefix, suffix});
    }
    
    return (int)max_prod;
    }
};