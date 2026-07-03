class Solution {
public:
    void dfs(int n, vector<vector<int>>& adj, vector<int> &visited){
        visited[n] = 1;
        for(int x = 0; x < (int)adj[n].size(); x++){//traverse coloumn wise so that we can count each city rows tell us about only single city if the city is connected or not 
            if(adj[n][x] == 1 && !visited[x]){
                dfs(x, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int p = adj.size();
        vector<int> visited(p, 0);
        int provinces = 0;
        for(int i = 0; i < p; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                provinces++;
            }
        }
        return provinces;
    }
};