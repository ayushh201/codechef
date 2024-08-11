class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &vis){
        if(i<0||i>=m||j<0||j>=n||vis[i][j]||grid[i][j]==0) return;
        vis[i][j]=true;
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i,j-1,vis);
    }
    int noOfIsland(vector<vector<int>>& grid){
        int island=0;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(grid,i,j,vis);
                    island++;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int islands=noOfIsland(grid);
        if(islands==0||islands>1) return 0;
        else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        islands=noOfIsland(grid);
                        if(islands==0||islands>1){
                            return 1;
                        }
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};
