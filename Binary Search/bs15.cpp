// WAP to find Nth root of a given number

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

double mypow(double a,ll b)
{
        double res=1;
        while(b>0)
        {
                if(b&1)
                        res=res*a;
                a=a*a;
                b=b>>1;
        }
        return res;
}
double findnthroot(ll num,ll n)
{
        double low=1,high=num;
        double eps = 1e-6; 
        while((high-low)>eps)
        {
                double mid=low+(high-low)/2.0;
                double res=mypow(mid,n);  // Binary exponentiation
                if(res>num)
                        high=mid;
                else
                        low=mid;
        }
        return low; //high-low will always be same, will differ after 5th decimal number
}
int main()
{
        FAST;
        ll testcases=1;
        // cin >> testcases;
        while(testcases--)
        {
                ll n,num,i;
                cin >> num >> n;
                double ans=findnthroot(num,n);
                cout << ans << "\n";
        }
}

