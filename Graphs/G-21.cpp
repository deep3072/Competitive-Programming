// Topological sort using DFS

class Solution
{
    void dfs(int node, stack<int>&st, vector<int>&vis, vector<int>adj[])
    {
        vis[node] = 1;
        for(auto neighbour:adj[node])
        {
            if(!vis[neighbour])
                dfs(neighbour, st, vis, adj);
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int i;
	    vector<int>vis(V, 0);
	    stack<int>st;
	    for(i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i, st, vis, adj);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};