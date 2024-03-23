// Detect cycle in directed graph using DFS

class Solution
{
    bool dfs(int node, vector<int>&vis, vector<int>&pathVisited, vector<int>adj[])
    {
        vis[node] = 1;
        pathVisited[node] = 1;
        for(auto neighbour:adj[node])
        {
            if(!vis[neighbour])
            {
                if(dfs(neighbour, vis, pathVisited, adj))
                    return true;
            }
            else if(pathVisited[neighbour])
                return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        int i;
        vector<int>vis(V, 0);
        for(i=0;i<V;i++)
        {
            if(!vis[i])
            {
                vector<int>pathVisited(V, 0);
                if(dfs(i, vis, pathVisited, adj))
                    return true;
            }
        }
        return false;
    }
};
