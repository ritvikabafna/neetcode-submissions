class Solution {
public:

    void solve(int i,int j,vector<vector<int>>& grid,int n,int m,int &area){
        if(i<0 || i>=n || j<0 || j>=m)
            return ;
        if(grid[i][j]==0)
            return ;
        grid[i][j]=0;
        area++;
        solve(i+1,j,grid,n,m,area);
        solve(i-1,j,grid,n,m,area);
        solve(i,j+1,grid,n,m,area);
        solve(i,j-1,grid,n,m,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                    solve(i,j,grid,n,m,area);
                    maxi=max(area,maxi);
                }
            }
        }
        if(maxi!=INT_MIN)
        return maxi;
        return 0;
    }
};
