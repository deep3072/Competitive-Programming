// WAP to allocate minimum number of pages. 

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

bool isvalid(int a[],int n,int m,int mid)
{
        int pages=0,student=1,i;
        for(i=0;i<n;i++)
        {
            pages+=a[i];
            if(pages>mid)
            {
                pages=a[i];
                student++;
            }
        }
        return (student<=m);
}
ll findPages(int a[], int n, int m) 
{
        int i,mx=-1,sum=0;
        if(n<m)
                return -1;
        for(i=0;i<n;i++)
        {
                mx=max(mx,a[i]);
                sum+=a[i];
        }
        int low=mx,high=sum,ans=sum;
        while(low<=high)
        {
                int mid=low+(high-low)/2;
                if(isvalid(a,n,m,mid))
                {
                        ans=mid;
                        high=mid-1;
                }
                else
                {
                        low=mid+1;
                }
        }
        return ans;
}
int main()
{
        FAST;
        ll testcases=1;
        // cin >> testcases;
        while(testcases--)
        {
                ll n,i;
                cin >> n;
                int a[100001];
                for(i=0;i<n;i++)
                        cin >> a[i];
                ll m;
                cin >> m;
                ll ans=findPages(a,n,m);
                cout << ans << "\n";
        }
}