// We can sort vector of pair ascending with first and second element, increasing according first and decreasing according second element, etc covering all possiblities.
#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define all(v1) v1.begin(),v1.end()

bool cmp(pair<int,int> x,pair<int,int> y) //first element increasing and if first is same then second element descending
{
        // if(x.first>y.first)
        //         return false;
        // else if(y.first>x.first)
        //         return true;
        // else
        // {
        //         if(x.second>y.second)
        //                 return true;
        //         else if(x.second<y.second)
        //                 return false;
        //         else
        //                 return true;
        // }
         
        //Another way to write it
        if(x.first!=y.first)
                return (x.first<y.first);
        return x.second>y.second;
}

bool cmp1(pair<int,int> x,pair<int,int> y) //first element decreasing and if first is same then second element increasing
{
        // if(x.first>y.first)
        //         return true;
        // else if(y.first>x.first)
        //         return false;
        // else
        // {
        //         if(x.second>y.second)
        //                 return false;
        //         else if(x.second<y.second)
        //                 return true;
        //         else
        //                 return true;
        // }
        
        //Another way to write it
        if(x.first!=y.first)
                return (x.first>y.first);
        return x.second<y.second;
}

void solve()
{
        int i,j;
        vector<pair<int,int>>a={
                {4,3},
                {5,3},
                {5,5},
                {7,9},
                {8,5},
                {25,6}};
        int n=6;
        
        
        sort(all(a)); // w/o using cmp it will sort both in ascending
        
        sort(all(a),cmp); // first->increasing, second->decreasing
        
        sort(all(a),cmp1); //first->decreasing, second->increasing
        
        sort(all(a),greater<>()); // for both descending use greater<>()
        
        for(i=0;i<n;i++)
                cout << a[i].first << " " << a[i].second << "\n";
}

int main()
{   
        FAST;
        ll testcases=1;
        // cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << t << ": ";
                solve();
        }
}