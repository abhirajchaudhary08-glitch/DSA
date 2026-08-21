class Solution {
public:
    int nearestDrone(vector<vector<int>>& d, vector<int>& t) {
        int bsti = -1;
        int mind= INT_MAX;
        for(int i=0;i<d.size();i++){
            int dis = abs(d[i][0]-t[0])+abs(d[i][1]-t[1]);
            if(dis<=d[i][2]){
                if(dis<mind){
                    mind = dis;
                    bsti =i;
                }
            }
        }
        return bsti;
    }
};