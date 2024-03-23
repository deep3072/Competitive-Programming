// Detect Cycle in an undirected graph using DFS

class Solution
{
    bool detect_usingDFS(int node, int parent, vector<int>adj[], vector<int>&vis)
    {
        vis[node] = 1;
        for(auto neighbour:adj[node])
        {
            if(!vis[neighbour])
            {
                if(detect_usingDFS(neighbour, node, adj, vis))
                    return true;
            }
            else if(neighbour != parent)
                return true;
        }
        return false;
    }
    public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>vis(V, 0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                // cout << i << "\n";
                if(detect_usingDFS(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};