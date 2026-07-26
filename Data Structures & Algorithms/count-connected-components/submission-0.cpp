class Solution {
public:
    void solve(vector<vector<int>> &adj,vector<bool> &vis,int src){
        if(vis[src])
        return;

        vis[src]=true;

        for(auto it:adj[src]){
            if(!vis[it]){
                solve(adj,vis,it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt=0;
        vector<bool> vis(n,false);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                solve(adj,vis,i);
                cnt++;
            }
        }
        return cnt;

    }
};
