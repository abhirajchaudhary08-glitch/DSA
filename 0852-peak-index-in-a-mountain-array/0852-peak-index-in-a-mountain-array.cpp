class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int n = arr.size();
    //   int l = 0;
    //   int h =n-1;
        auto p = max_element(arr.begin(),arr.end());
        int idx = distance(arr.begin(),p);
        return idx;
    }
};