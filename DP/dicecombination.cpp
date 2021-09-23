// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

// Input:
// 3

// Output:
// 4

// Constraints:
// 1 ≤ n ≤ 10^6

#include<bits/stdc++.h>
using namespace std;

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
        ll n,i,j;
        cin >> n;
        vector<ll>dp(n+1,0);
        // dp[i] represents number of valid ways to contruct sum equals to i by throwing a dice one or more times;
        // we want dp[n];
        dp[0]=1;
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=6;j++)
                {
                        if(j>i)
                                br;
                        dp[i] = mod_add(dp[i],dp[i-j],mod);
                }
        }
        cout << dp[n] << "\n";
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
 