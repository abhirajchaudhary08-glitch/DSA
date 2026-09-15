// class Solution {
// public:
//     bool uniformArray(vector<int>& arr) {
//         int n=arr.size();
//         int e=0;
//         int o=0;
//         int smallest_odd=INT_MAX;
//         for(int i=0;i<n;i++){
//             if(arr[i]%2==0) e++;
//             else {
//                 o++;
//                 smallest_odd=min(smallest_odd,arr[i]);
//             }
//         }
//         if(e==n) return true;
//         else if(o==n) return true;
//         else {
//            for(int i=0;i<n;i++){
//                if(arr[i] % 2==0){
//                    if(arr[i]<smallest_odd) return false;
//                }
//            } 
//         }
//     return true;
//     }
// };
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        bool odd=false;
        for(auto t:nums1){
            
            if(t%2){
                odd=true;
                mini=min(mini,t);
            }
        }
        if(!odd) return true;
        for(int t:nums1){
            if(t%2==0 && mini>t) return false;
        }
        return true;
    }
};