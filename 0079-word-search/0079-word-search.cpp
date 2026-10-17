class Solution {
public:
    int m,n;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool f(vector<vector<char>>& board,int i, int j, int idx, string& word){
        if(idx == word.length())
           return true;
        if(i<0||j<0||i>=m||j>=n||board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &d : dir){
            int n_i = i+d[0];
            int n_j = j+d[1];
            if(f(board,n_i,n_j,idx+1,word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && f(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};