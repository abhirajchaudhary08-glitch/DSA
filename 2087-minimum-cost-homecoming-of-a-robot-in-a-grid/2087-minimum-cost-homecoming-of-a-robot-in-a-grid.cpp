// class Solution {
// public:
//     int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
//         int totcost = 0;
//         int rdir = (startPos[0]<homePos[0]) ? 1:-1;
//         for(int i =startPos[0]+rdir;i!=homePos[0]+rdir;i+=rdir){
//             totcost+=rowCosts[i];
//         }
//         int cDir = (startPos[1] < homePos[1]) ? 1 : -1;
//         for (int j = startPos[1] + cDir; j != homePos[1] + cDir; j += cDir) {
//             totcost += colCosts[j];
//         }
//         return totcost;
//     }
// };
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int sx = startPos[0], sy = startPos[1];
        int tx = homePos[0], ty = homePos[1];

        int cost = 0;

       
        while (sx < tx) {
            sx++;
            cost += rowCosts[sx];
        }
        while (sx > tx) {
            sx--;
            cost += rowCosts[sx];
        }

        
        while (sy < ty) {
            sy++;
            cost += colCosts[sy];
        }
        while (sy > ty) {
            sy--;
            cost += colCosts[sy];
        }

        return cost;
    }
};