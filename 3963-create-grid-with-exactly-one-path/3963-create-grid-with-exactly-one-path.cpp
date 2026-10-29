class Solution {
public:
    vector<string> createGrid(int m, int n) {
            vector<string> grid(m, string(n, '#'));
        
        if (n == 1) {
            for (int i = 0; i < m; i++) {
                grid[i][0] = '.';
            }
            return grid;
        }
        
        int bend = n - 2; 
        for (int j = 0; j <= bend; j++) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; i++) {
            grid[i][bend] = '.';
        }
        for (int j = bend; j < n; j++) {
            grid[m - 1][j] = '.';
        }
        
        return grid;
    }
};