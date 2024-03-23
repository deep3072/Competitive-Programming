// Shortest Path in DAG using Topo Sort
// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution
{   
    void topoSort(int node, stack<int>&st, vector<int>&vis, vector<pair<int,int>>adj[])
    {
        vis[node] = 1;
        for(auto neighbour:adj[node])
        {
            int nnode = neighbour.first;
            int d = neighbour.second;
            if(!vis[nnode])
            {
                topoSort(nnode, st, vis, adj);
            }
        }
        st.push(node);
    }
    public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        int i;
        // Make the graph
        vector<pair<int, int>>adj[N];
        for(i=0;i<M;i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            
        // step1
        stack<int>st;
        vector<int>vis(N, 0);
        for(i=0;i<N;i++)
        {
            if(!vis[i])
                topoSort(i, st, vis, adj);
        }
        
        // step 2: Do the edge relaxtion
        vector<int>dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for(i=0;i<N;i++)
        {
            if(dist[i] == 1e9) // not reachables
                dist[i] = -1;
        }
        return dist;
        
    }
}