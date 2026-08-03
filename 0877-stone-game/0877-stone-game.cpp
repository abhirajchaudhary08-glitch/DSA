class Solution {
public:
    int t[502][502];
    bool visited[502][502];
    int f(vector<int>& nums,int left,int right){
        if(left>right) return 0;
        if(visited[left][right]){
            return t[left][right];
        }
        visited[left][right] = true;
        int takeleft = nums[left]-f(nums,left+1,right);
        int takeright = nums[right]-f(nums,left,right-1);
        t[left][right] = max(takeleft,takeright);
        return t[left][right];
    }
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        memset(visited,false,sizeof(visited));
        return f(nums,0,n-1)>0;
    }
};