class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        for(int i=0;i<servers.size();i++)
        {
            pq.push({servers[i],i});
        }

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> av;

        vector<int> result;
        long long t = 0;

        for(int i=0;i<tasks.size();i++)
        {
            t = max(t,1LL*i);
            while(!av.empty() && av.top().first<=t)
            {
                pq.push({servers[av.top().second],av.top().second});
                av.pop();
            }

            if(pq.empty())
            {
                t = av.top().first;
                while(!av.empty() && av.top().first<=t)
                {
                    pq.push({servers[av.top().second],av.top().second});
                    av.pop();
                }
            }

                result.push_back(pq.top().second);
                av.push({t+1LL*tasks[i],pq.top().second});
                pq.pop();
        }

        return result;

    }
};
