class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> mxh(nums.begin(),nums.end());
       for(int i = 0;i<k-1;i++){
            if(!mxh.empty()){
                int p=mxh.top();
                mxh.pop();
            }
       }
       return mxh.top();

    }
};