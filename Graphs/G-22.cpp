// Topo sort using BFS - Kahn's Algorithm
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int i;
	    vector<int>ans, indegree(V, 0);
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
	        ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q1.push(it);
            }
	    }
	    return ans;
	}
}