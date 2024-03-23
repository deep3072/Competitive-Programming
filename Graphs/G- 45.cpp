class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>,
        vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0}); // {wt, node}
        
        vector<int>vis(V, 0);
        int sum = 0;
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int node = curr.second;
            if(vis[node] == 1)
                continue;
	    // adding node to mst
            vis[node] = 1;
            sum += wt;
            for(auto it:adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode])
                    pq.push({edW, adjNode});
            }
        }
        return sum;
    }
};

// if tree was asked then take parent also in pq;