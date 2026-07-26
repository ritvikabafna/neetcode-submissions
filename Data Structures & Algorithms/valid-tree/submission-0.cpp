class Solution {
public:
    bool isCycle(vector<bool> &vis,vector<vector<int>> &adj,int src ,int par){
        if(vis[src])
            return true;
        vis[src]=true;
        for(auto neigh: adj[src]){
            if(!vis[neigh]){
                if(isCycle(vis,adj,neigh,src)){
                    return true;
                }
                
            }
            else if(vis[neigh] && neigh!=par)
                return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(adj.size(), false);
        int par=-1;
        if(isCycle(vis,adj,0,par))
            return false;
        for(int i=0;i<vis.size();i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
};
