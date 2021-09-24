#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define mni INT_MIN
#define mxi INT_MAX
#define mod 1000000007 // 998244353
#define all(v1) v1.begin(),v1.end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define um unordered_map
#define ff first
#define ss second
#define bb begin
#define cont continue
#define ret return
#define br break

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mypow(ll a, ll b) { ll res=1; while(b>0) { if(b&1) res=mod_mul(res,a,mod); a=mod_mul(a,a,mod); b=b>>1; } return res; }
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mypow(b, m-2),m) + m) % m;}  
ll gcd(ll a,ll b) { if(!b) return a; return gcd(b,a%b);}

//--------------------------------------------------------------------------------------------------------------------------

void solve()
{
        // All of the below operations happens in log(n) time except size() operations (obviously);
        pbds pb;
        pb.insert(11);
        pb.insert(10);
        pb.insert(102);
        pb.insert(1);
        pb.insert(5);
        
        // Stored as 1 5 10 11 102
        // Printing all elements;
        cout << "Print elements: ";
        for(auto it:pb)
                cout << it << " ";
        cout << "\n";
        
        // Kth smallest element;
        int k=4;
        cout << k << "th smallest: " << *pb.find_by_order(k-1) << "\n";
        
        // Count of Number of elements  <  X;
        int X = 6;
	cout << "No of elements less than " << X << " are " << pb.order_of_key(X) << "\n";
        
        //DELETE Elements
        cout << "5 Deleted\n";
        pb.erase(5);
        cout << pb.size() << "\n";
        
        //NEXT BIGGER ELEMENT than X
        X = 8;
        cout << "Next greater element than " << X << " is " << *pb.upper_bound(X) << "\n";
        
}

int main()
{   
        FAST;
        ll testcases=1;
        cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << t << ": ";
                solve();
        }
}
 