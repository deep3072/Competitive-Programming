// Problem link : https://cses.fi/problemset/task/1636/

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
        ll i,n,x,j;
        cin >> n >> x;
        vector<ll>coins(n+1);
        for(i=1;i<=n;i++)
                cin >> coins[i];
        // vector<vector<ll>>dp(n+1,vector<ll>(x+1));
        int dp[n+1][x+1];
        // dp[i][x] : number of valid ways to make sum x using coins c0 to ci;
        // ans : dp[n][x];
        // dp[i][x] = dp[i-1][x] + dp[i][x-ci];
        // Time : O(NX)
        // dp[i][0]=1;
        for(i=1;i<=n;i++)
        {
                for(j=0;j<=x;j++)
                {
                        if(j==0)
                                dp[i][j]=1; // base case;
                        else{
                                ll op1=0,op2=0;
                                if(coins[i]<=j)
                                        op1 =  dp[i][j-coins[i]]; //taking ith coin;
                                if(i!=1)
                                        op2 = dp[i-1][j]; // not taking ith coin;
                                dp[i][j] = mod_add(op1,op2,mod);
                        }
                }
        }
        cout << dp[n][x];
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