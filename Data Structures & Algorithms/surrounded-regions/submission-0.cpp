class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }
    void solve(vector<vector<char>>& grid,int n,int m,queue<pair<int,int>>& q){
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            grid[i][j]='v';

            if(isSafe(i+1,j,n,m) && grid[i+1][j]=='O'){
                grid[i+1][j]='v';
                q.push(make_pair(i+1,j));
            }
            if(isSafe(i-1,j,n,m) && grid[i-1][j]=='O'){
                grid[i-1][j]='v';
                q.push(make_pair(i-1,j));
            }
            if(isSafe(i,j+1,n,m) && grid[i][j+1]=='O'){
                grid[i][j+1]='v';
                q.push(make_pair(i,j+1));
            }
            if(isSafe(i,j-1,n,m) && grid[i][j-1]=='O'){
                grid[i][j-1]='v';
                q.push(make_pair(i,j-1));
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        if (grid.empty())
            return;
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

    for (int j = 0; j < m; j++) {
        if(grid[0][j]=='O'){
            q.push({0,j});
        }
    }

    // 2. Right Column: Top to Bottom
    for (int i = 1; i < n; i++) {
        if(grid[i][m-1]=='O'){
            q.push({i,m-1});
        }
    }

    // 3. Bottom Row: Right to Left
    for (int j = m - 2; j >= 0; j--) {
        if(grid[n-1][j]=='O'){
            q.push({n-1,j});
        }
    }

    // 4. Left Column: Bottom to Top
    for (int i = n - 2; i >= 1; i--) {
        if(grid[i][0]=='O'){
            q.push({i,0});
        }
    }

        if(q.empty()){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='O')
                grid[i][j]='X';
        }
    }
    return;
}
        else{
            solve(grid,n,m,q);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='O')
                        grid[i][j]='X';
                    else if(grid[i][j]=='v')
                        grid[i][j]='O';
                 }
            }
        }
    }
};
