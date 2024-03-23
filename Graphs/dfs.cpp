// DFS
class Solution
{
    void dfs(int cur, vector<int> &vis, vector<int> adj[], vector<int>&ans)
    {
        vis[cur] = 1;
        ans.push_back(cur);
        for(auto neighbour:adj[cur])
        {
            if(!vis[neighbour])
            {
                dfs(neighbour, vis, adj, ans);
            }
        }
    }
    public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>ans;
        vector<int>vis(V, 0);
        dfs(0, vis, adj, ans);
        return ans;
    }
};