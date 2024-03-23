// Kosaraju's Algorithm

class Solution
{
    private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    private:
    void dfs3(int node, vector<int>&vis, vector<vector<int>>&adj)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs3(it, vis, adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st; // nodes in order of finishing time
        vector<int>vis(V, 0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        
        // Now, reverse the graph
        vector<vector<int>>revAdj(V);
        for(int i=0;i<adj.size();i++)
        {
            vis[i] = 0;
            for(int j=0;j<adj[i].size();j++)
            {
                // i -> adj[i][j] to adj[i][j] -> i
                revAdj[adj[i][j]].push_back(i);
            }
        }
        
        int scc = 0;
        // Perform dfs on finishing time
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!vis[node])
            {
                scc++;
                dfs3(node, vis, revAdj);
            }
        }
        return scc;
    }
};