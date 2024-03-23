// Dijkstra's Algorithm - Using Set

class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>>s1;
        s1.insert({0, S});
        
        vector<int>dist(V, INT_MAX);
        dist[S] = 0;
        while(!s1.empty())
        {
            auto curr = *(s1.begin());
            s1.erase(curr);
            
            int d = curr.first;
            int node = curr.second;
            for(neighbour:adj[node])
            {
                int adjNode = neighbour[0];
                int edgewt = neighbour[1];
                if((d + edgewt) < dist[adjNode])
                {
                    if(dist[adjNode] != INT_MAX) // already reached earlier with high distance
                        s1.erase({dist[adjNode], adjNode}); // so we remove it from set and decrease operations. This is not possible in priority queue;
                        
                    dist[adjNode] = d + edgewt;
                    s1.insert({dist[adjNode], adjNode});
                }
            }
            
        }
        return dist;
    }
}