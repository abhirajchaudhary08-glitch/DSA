class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i + 1;
        
        // n elements yield (n - 1) adjacent pairs
        vector<int> arr(n - 1);
        while (j < n) {
            arr[i] = nums[i] + nums[j];
            i++;
            j++;
        }
        
        unordered_map<int, int> mp;
        for (auto &x : arr) {
            mp[x]++;
            // Check the frequency of sum x in the hash map
            if (mp[x] == 2) {
                return true;
            }
        }
        
        return false;
    }
};