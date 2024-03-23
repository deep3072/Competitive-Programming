// Kruskal's Algorithm

class DisjointSet
{
        vector<int> rank, parent, size;
        public:
        
        DisjointSet(int n)
        {
                parent.resize(n+1); 
                rank.resize(n+1, 0);
                size.resize(n+1, 1);
                for(int i=0;i<=n;i++)
                        parent[i] = i;
        }
        
        int findUPar(int node)
        {
                if(node == parent[node])
                        return node;
                return (parent[node] = findUPar(parent[node])); 
        }
        
        void unionByRank(int u, int v)
        {
                int ulp_u = findUPar(u);
                int ulp_v = findUPar(v);
                if(ulp_u == ulp_v) 
                        return;
                if(rank[ulp_u] < rank[ulp_v]) // 
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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Kruskal's Algo
        vector<pair<int, pair<int, int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        DisjointSet ds(V);
        for(int i=0;i<edges.size();i++)
        {
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};