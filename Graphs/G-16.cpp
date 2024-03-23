// Number of distinct islands

class Solution
{
    private:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isValid(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    void dfs(int row, int col, int row0, int col0, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int, int>>&v1)
    {
        vis[row][col] = 1;
        v1.push_back({row-row0, col-col0});
        for(int k=0;k<4;k++)
        {
            int nrow = row + directions[k][0];
            int ncol = col + directions[k][1];
            if(isValid(nrow, ncol, grid.size(), grid[0].size()) && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, row0, col0, grid, vis, v1);
            }
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int i, j;
        set<vector<pair<int, int>>>s1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>>v1;
		    // n * m * 4
                    dfs(i, j, i, j, grid, vis, v1);
                    s1.insert(v1);
                }
            }
        }
	// Time : O(n*m*log(n*m)) + O(n*m*4)
        return s1.size();
    }
};