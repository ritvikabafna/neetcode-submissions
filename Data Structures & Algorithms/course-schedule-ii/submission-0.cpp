class Solution {
public:
    bool isCycle(int i,vector<vector<int>> &adj, vector<bool>& vis,vector<bool> &rec,stack<int>&s){
        if(rec[i])
            return true;
        if(vis[i])
            return false;
        
        vis[i]=true;
        rec[i]=true;

        for(auto j:adj[i]){
            if(!vis[j]){
                if(isCycle(j,adj,vis,rec,s))
                    return true;
                
            }
            else if (rec[j]) {
            return true;
            }

        }
        s.push(i);
        rec[i] = false; 
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);    
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);
        stack<int>s;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,rec,s))
                    return {};
            }
            
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
