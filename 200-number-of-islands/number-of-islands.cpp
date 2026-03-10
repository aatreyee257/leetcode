class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int icount = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'&& !vis[i][j]){
                    icount++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return icount;
    }
    void dfs(int rows,int cols,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        if(rows<0||row<=rows || cols<0 || col<=cols || vis[rows][cols] || grid[rows][cols]=='0'){
            return;
        }
        vis[rows][cols]=1;
        dfs(rows-1,cols,vis,grid);
        dfs(rows+1,cols,vis,grid);
        dfs(rows,cols-1,vis,grid);
        dfs(rows,cols+1,vis,grid);
    }
};