// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         vector<int> ans;
//         int n = boxes.length();
//         for(int i = 0;i<n;i++){
//             int sum = 0;
//             for(int j=0;j<n;j++){
//                 if(boxes[j]=='1'){
//                     sum+=abs(i-j);
//                 }

//             }
//             ans.push_back(sum);
//         }
//         return ans;
//     }
// };//try to use prefix and suffix sum when ever there is a need of two loops
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left(n, 0), right(n, 0), res(n, 0);
        int count = (boxes.at(0) == '1' ? 1 : 0);

        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + count;
            count += (boxes.at(i) == '1' ? 1 : 0);
        }

        count = (boxes.at(n-1) == '1' ? 1 : 0);

        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + count;
            count += (boxes.at(i) == '1' ? 1 : 0);
        }

        for (int i = 0; i < n; i++) {
            res[i] = left[i] + right[i];
        }

        return res;
    }
};