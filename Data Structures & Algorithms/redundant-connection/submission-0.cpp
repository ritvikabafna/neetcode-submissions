class Solution {
public:
    bool solve(vector<vector<int>> &adj,vector<bool> &vis, int u,int v ){
        
        vis[u]=true;
        if(u==v)
            return true;
        for(auto it:adj[u]){
            if(!vis[it]){
               if(solve(adj,vis,it,v)) {
                return true;
               }
            }
            
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1); 
        int u=edges[0][0];
        int v=edges[0][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        for(int i=1;i<edges.size();i++){
            vector<bool>vis(n+1,false);
            int u=edges[i][0];
            int v=edges[i][1];
            if(solve(adj,vis,u,v)){
                return{u,v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
