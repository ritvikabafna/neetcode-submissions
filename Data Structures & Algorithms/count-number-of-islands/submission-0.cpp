class Solution {
public:
    
    void solve(int i,int j,vector<vector<char>>&grid,int n,int m){
        if(i>=n || j>=m || i<0 || j<0)
            return;
        
        if(grid[i][j]=='0')
            return;
        
        if(grid[i][j]=='1')
            grid[i][j]='0';
        solve(i+1,j,grid,n,m);
        solve(i-1,j,grid,n,m);
        solve(i,j+1,grid,n,m);
        solve(i,j-1,grid,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    solve(i,j,grid,n,m);
                }
            }
        }
        return cnt;
    }
};
