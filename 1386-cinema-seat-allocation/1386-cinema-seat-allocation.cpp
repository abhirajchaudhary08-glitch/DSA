class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> rows;

        for (auto& r : reservedSeats) {
            int row = r[0], seat = r[1];
            if (rows.find(row) == rows.end()) {
                rows[row] = vector<bool>(11, false); 
            }
            rows[row][seat] = true;
        }

        long long count = (long long)(n - rows.size()) * 2;

        for (auto& [row, seats] : rows) {
            bool leftFree  = !seats[2] && !seats[3] && !seats[4] && !seats[5];
            bool midFree   = !seats[4] && !seats[5] && !seats[6] && !seats[7];
            bool rightFree = !seats[6] && !seats[7] && !seats[8] && !seats[9];

            if (leftFree && rightFree) {
                count += 2;
            } else if (leftFree || midFree || rightFree) {
                count += 1;
            }
        }

        return (int)count;
    }
};