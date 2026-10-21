class Solution {
public:

    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        vector<int> arr;
        for(int i=0;i<n1.size();i++){
             arr.push_back(n1[i]);
         }
         for(int j = 0; j<n2.size();j++){
            arr.push_back(n2[j]);
         }
         sort(arr.begin(),arr.end());
        int p = arr.size();
    double m = 0;

    if (p % 2 == 0) {
    int t = (p - 1) / 2;
    int y = p / 2; // or (p + 1) / 2
    m = (arr[t] + arr[y]) / 2.0; 
    } else {
    int f = p / 2;
    m = arr[f]; 
    }

    return m;
    }
};