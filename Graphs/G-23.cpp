// Cycle detection in a directed graph using Kahn's Algorithm

class Solution
{
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        int i, cnt = 0;
	    vector<int>indegree(V, 0);
	    for(i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	            indegree[it]++;
	    }
	    queue<int>q1;
	    for(i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	            q1.push(i);
	    }
	    while(!q1.empty())
	    {
	        int node = q1.front();
	        q1.pop();
	        cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q1.push(it);
            }
	    }
	    return (cnt != V);
    }
}