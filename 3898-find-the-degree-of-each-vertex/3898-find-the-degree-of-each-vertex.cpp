class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i = 0;i<matrix.size();i++){
            int ct = 0;
            for(int j =0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    ct++;
                }
            }
            ans.push_back(ct);
        }
        return ans;
    }
};