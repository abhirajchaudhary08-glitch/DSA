class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int maxRadius = 0;
        for (int house : houses) {
            auto rightHeater = lower_bound(heaters.begin(), heaters.end(), house);
            int distRight = (rightHeater != heaters.end()) ? (*rightHeater - house) : INT_MAX;
            int distLeft = (rightHeater != heaters.begin()) ? (house - *(rightHeater - 1)) : INT_MAX;
            int closestHeater = min(distLeft, distRight);
            maxRadius = max(maxRadius, closestHeater);
        }
        
        return maxRadius;
    }
};