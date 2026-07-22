class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }
    void solve(queue<pair<int,int>> &q,int n,int m,vector<vector<int>>& grid){

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
        
            if(isSafe(i+1,j,n,m) && grid[i+1][j]==INT_MAX){
                grid[i+1][j]=grid[i][j]+1;
                q.push(make_pair(i+1,j));
            }
            if(isSafe(i-1,j,n,m) && grid[i-1][j]==INT_MAX){
                grid[i-1][j]=grid[i][j]+1;
                q.push(make_pair(i-1,j));
            }
            if(isSafe(i,j+1,n,m) && grid[i][j+1]==INT_MAX){
                grid[i][j+1]=grid[i][j]+1;
                q.push(make_pair(i,j+1));
            }
             if(isSafe(i,j-1,n,m) && grid[i][j-1]==INT_MAX){
                grid[i][j-1]=grid[i][j]+1;
                q.push(make_pair(i,j-1));
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty())
            return;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                    q.push(make_pair(i,j));
            }
        }
        solve(q,n,m,grid);
    }
};
