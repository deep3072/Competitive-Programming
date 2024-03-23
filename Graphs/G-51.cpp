class DisjointSet
{
        public:
        vector<int> rank, parent, size;
        
        DisjointSet(int n)
        {
                parent.resize(n+1); 
                rank.resize(n+1, 0); // use either rank or size
                size.resize(n+1, 1);
                for(int i=0;i<=n;i++)
                        parent[i] = i;
        }
        
        int findUPar(int node)
        {
                if(node == parent[node])
                        return node;
                return (parent[node] = findUPar(parent[node])); // pathcompression
        }
        
        void unionByRank(int u, int v)
        {
                int ulp_u = findUPar(u);
                int ulp_v = findUPar(v);
                if(ulp_u == ulp_v) // if in same component already
                        return;
                if(rank[ulp_u] < rank[ulp_v]) // no change in rank if smaller node gets attached to larger
                        parent[ulp_u] = ulp_v;
                else if(rank[ulp_u] > rank[ulp_u])
                        parent[ulp_v] = ulp_u;
                else{
                        parent[ulp_v] = ulp_u;
                        rank[ulp_u]++;
                }
        }
        void unionBySize(int u, int v)
        {
                int ulp_u = findUPar(u);
                int ulp_v = findUPar(v);
                if(ulp_u == ulp_v) // if in same component already
                        return;
                if(size[ulp_u] < size[ulp_v])
                {
                        parent[ulp_u] = ulp_v;
                        size[ulp_v] += size[ulp_u];
                }
                else{
                        parent[ulp_v] = ulp_u;
                        size[ulp_u] += size[ulp_v];
                }
        }
};

int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool isValid(int r, int c, int n, int m)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}
class Solution 
{
    public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int i, j;
        DisjointSet ds(n*m);
        int cnt = 0;
        vector<int> ans;
        for(i=0;i<operators.size();i++)
        {
            int r = operators[i][0];
            int c = operators[i][1];
            int node = r*m + c;
            if(!vis[r][c])
            {
                vis[r][c] = 1;
                cnt++;
                for(int k=0;k<4;k++)
                {
                    int nrow = r + directions[k][0];
                    int ncol = c + directions[k][1];
                    if(isValid(nrow, ncol, n, m) && vis[nrow][ncol] == 1)
                    {
                        int adjNode = nrow*m + ncol;
                        if(ds.findUPar(node) != ds.findUPar(adjNode))
                        {
                            ds.unionBySize(node, adjNode);
                            cnt--;
                        }
                    }
                } 
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};