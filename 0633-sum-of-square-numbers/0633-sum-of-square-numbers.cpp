class Solution {
public:
    bool judgeSquareSum(int c) {
        // for(int i=0;i<c+1;i++){
        //     for(int j = i;j<c+1;j++){
        //         if(c==i*i+j*j) return true;
        //     }
        // }
        // return false;
        int left = 0;
        int right = sqrt(c);
        
        while(left<=right){
            if(c-left*left==right*right) return true;
            else if(c-left*left>right*right){
                left++;
            }else{
                right--;
            }

        }
        return false;
    }
};