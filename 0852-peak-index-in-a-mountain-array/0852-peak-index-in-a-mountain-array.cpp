class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int n = arr.size();
    //     auto p = max_element(arr.begin(),arr.end());
    //     int idx = distance(arr.begin(),p);
    //     return idx; use binary search instead
    int l =1;
    int h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
            return mid;
            break;
        }else if(arr[mid]>arr[mid+1] ){
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
    }
};