// Shortest path in Undirected Graph having unit distance

class Solution
{
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src)
    {
        int i;
        vector<int>dist(n, -1);
        vector<int>adj[n];
        for(i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q1;
        q1.push(src);
        dist[src] = 0;
        while(!q1.empty())
        {
            auto curr = q1.front();
            q1.pop();
            for(auto neighbour:adj[curr])
            {
                if(dist[neighbour] == -1)
                {
                    dist[neighbour] = dist[curr] + 1;
                    q1.push(neighbour);
                }
            }
        }
        return dist;
    }
}