class Solution {
public:

    bool isCycle(int i,vector<vector<int>> &adj, vector<bool>& vis,vector<bool> &rec){
        if(rec[i])
            return true;
        if(vis[i])
            return false;
        
        vis[i]=true;
        rec[i]=true;

        for(auto j:adj[i]){
            if(!vis[j]){
                if(isCycle(j,adj,vis,rec))
                    return true;
                
            }
            else if (rec[j]) {
            return true;
            }

        }

        rec[i] = false; 
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);    
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,rec))
                    return false;
            }
            
        }
        return true;
        
    }
};
