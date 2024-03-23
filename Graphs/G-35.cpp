// Find Shortest Path in weighted undirected graph - Dijkstra's Algo

class Solution
{
    public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        vector<pair<int, int>>adj[n+1];
        int i;
        for(i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int>dist(n+1, INT_MAX), parent(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 1});
        
        for(i=1;i<=n;i++) 
            parent[i] = i;
        dist[1] = 0;
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int node = curr.second;
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if(d + wt < dist[adjNode])
                {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == INT_MAX)
            return {-1};
        
        vector<int>path;
        int node = n;
        while(parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
        
    }
}