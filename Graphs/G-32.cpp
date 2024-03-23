// Dijlstra's Algorithm - using Priority Queue
class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // {distance, node}
        vector<int>dist(V, INT_MAX);
        pq.push({0, S});
        dist[S] = 0;
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int pathDist = curr.first;
            int node = curr.second;
            for(auto neighbour:adj[node])
            {
                int adjNode = neighbour[0];
                int edgewt = neighbour[1];
                
                if((pathDist + edgewt) < dist[adjnode])
                {
                    dist[adjnode] = edgewt + dist[node];
                    pq.push({pathDist, adjNode});
                }
            }
        }
        return dist;
    }
}