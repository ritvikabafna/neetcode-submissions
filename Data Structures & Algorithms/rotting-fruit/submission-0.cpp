class Solution {
public:
    int cnt=0;

    bool isSafe(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }

    void solve(vector<vector<int>>& grid,int n,int m,queue<pair<int,int>> &q){
        while(!q.empty()){

            int size=q.size();
            bool rotten=false;

            for(int k=0;k<size;k++){
                int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if(isSafe(i+1,j,n,m) && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push(make_pair(i+1,j));
                rotten=true;
            }
            if(isSafe(i-1,j,n,m) && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push(make_pair(i-1,j));
                rotten=true;
            }
            if(isSafe(i,j+1,n,m) && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push(make_pair(i,j+1));
                rotten=true;
            }
             if(isSafe(i,j-1,n,m) && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push(make_pair(i,j-1));
                rotten=true;
            }
            }
            if(rotten==true)
                cnt++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return -1;
        int n=grid.size();
        int m=grid[0].size();
        bool fresh=true;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push(make_pair(i,j));
                if(grid[i][j]==1)
                    fresh=false;
            }
        }
        if(fresh)
            return 0;

        if(q.empty())
            return -1;
        
        solve(grid,n,m,q);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;  
            }
        }
        return cnt;
    }
};
