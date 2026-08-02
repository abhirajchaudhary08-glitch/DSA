class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> t(n,1);
        // int mxlis = 1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]){
        //         t[i] = max(t[i],t[j]+1);//ith position waale element ke saath lis vs jth position waale ko usme add krne ke baad un dono me jo maximum ho
        //         mxlis = max(mxlis,t[i]);
        //         }
        //     }
        // }
        // return mxlis;
        int n = nums.size();
        vector<int> sorted;//empty in the begining
        for(int i =0;i<n;i++){
            auto it = lower_bound(begin(sorted),end(sorted),nums[i]);//just greater than or equal to nums[i]
            if(it==end(sorted)){
                sorted.push_back(nums[i]);// greatest so insert it 
            }else{
                *it = nums[i];//replace with nums[i]
            }
        }
        return sorted.size();//
    }
};