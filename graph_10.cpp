class Solution {
public:

    bool isvalid(int x, int y, int n,int m)
    {
        return (x>=0&&x<n&&y>=0&&y<m);
    }

    void dfs(vector<vector<char>>grid, vector<vector<bool>>&vis,int l,int h,int n,int m)
    {
        vis[l][h]=true;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==j&&i==0)
                {
                    continue;
                }
                if(isvalid(l+i,h+j,n,m))
                {
                    dfs(grid,vis,l+i,h+j,n,m);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>>vis(n,vector<bool>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    vis[i][j]=false;
                }
                else
                {
                    vis[i][j]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    dfs(grid,vis,i,j,n,m);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
