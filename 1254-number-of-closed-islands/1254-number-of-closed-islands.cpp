class Solution {
private: void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        vis[r][c]=1;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && 
            vis[nr][nc]==0 && grid[nr][nc]==0)
            {
                dfs(nr,nc,grid,vis);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||j==n-1||i==m-1)
                {
                    if(grid[i][j]==0)
                    {
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }  
        int count=0;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==0)
                {
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }      
        return count;
    }
};