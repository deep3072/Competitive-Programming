#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
        public:
        vector<int> rank, parent, size;
        
        DisjointSet(int n)
        {
                parent.resize(n+1); 
                rank.resize(n+1, 0); // use either rank or size
                size.resize(n+1, 1);
                for(int i=0;i<=n;i++)
                        parent[i] = i;
        }
        
        int findUPar(int node)
        {
                if(node == parent[node])
                        return node;
                return (parent[node] = findUPar(parent[node])); // pathcompression
        }
        
        void unionByRank(int u, int v)
        {
                int ulp_u = findUPar(u);
                int ulp_v = findUPar(v);
                if(ulp_u == ulp_v) // if in same component already
                        return;
                if(rank[ulp_u] < rank[ulp_v]) // no change in rank if smaller node gets attached to larger
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

int main()
{
        DisjointSet ds(7);
        ds.unionBySize(1, 2);
        ds.unionBySize(2, 3);
        ds.unionBySize(4, 5);
        ds.unionBySize(6, 7);
        ds.unionBySize(5, 6);
        
        // if 3 and 7 are connected or not;
        if(ds.findUPar(3) == ds.findUPar(7))
                cout << "Connected\n";
        else cout << "Not Connected\n";
        ds.unionBySize(3, 7);
        if(ds.findUPar(3) == ds.findUPar(7))
                cout << "Connected\n";
        else cout << "Not Connected\n";
}
