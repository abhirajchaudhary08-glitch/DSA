class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> rowPref(m, vector<long long>(n));
        for (int i = 0; i < m; i++) {
            rowPref[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rowPref[i][j] = rowPref[i][j - 1] + grid[i][j];
            }
        }

        vector<vector<long long>> colPref(m, vector<long long>(n));
        for (int j = 0; j < n; j++) {
            colPref[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                colPref[i][j] = colPref[i - 1][j] + grid[i][j];
            }
        }

        long long total = 0;
        for (int i = 0; i < m; i++) total += rowPref[i][n - 1];

        long long topSum = 0;
        for (int i = 0; i < m - 1; i++) {
            topSum += rowPref[i][n - 1];
            if (topSum * 2 == total) return true;
        }

        long long leftSum = 0;
        for (int j = 0; j < n - 1; j++) {
            leftSum += colPref[m - 1][j];
            if (leftSum * 2 == total) return true;
        }

        return false;
    }
};