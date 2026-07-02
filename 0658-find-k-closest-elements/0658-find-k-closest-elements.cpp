class Solution {
public:
        typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> pq;
        for(int ele : arr){
            int dis = abs(x-ele);
            pi p = {dis,ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};