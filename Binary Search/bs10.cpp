
// WAP to find minimum absolute difference between key and array element.

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll floor(vector<ll>arr,ll target)
{
        ll n=arr.size();
        ll low=0,high=n-1;
        ll res=-1; //-1 means floor not found
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]==target)
                        return target;
                else if(arr[mid]>target)
                        high=mid-1;
                else
                {
                        res=max(res,arr[mid]);
                        low=mid+1;
                }
        }
        return res;
}

ll ceil(vector<ll>arr,ll target)
{
        ll n=arr.size();
        ll low=0,high=n-1;
        ll res=INT_MAX; // INT_MAX means ceil not found
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]==target)
                        return target;
                else if(arr[mid]<target)
                        low=mid+1;
                else
                {
                        res=min(res,arr[mid]);
                        high=mid-1;
                }
        }
        return res;
}

int main()
{
        FAST;
        ll testcases=1;
        cin >> testcases;
        while(testcases--)
        {
                ll n,i;
                cin >> n;
                vector<ll>arr(n);
                for(i=0;i<n;i++)
                        cin >> arr[i];
                ll key;
                cin >> key;
                ll a1=floor(arr,key);
                ll a2=ceil(arr,key); //If not call both func than just find floor index and floor ind+1 will only be ceil index.
                ll ans=a2;
                if(abs(a2-key)>abs(a1-key))
                        ans=a1;
                cout << ans << "\n";
				// Another way is to simply apply binary search, if key found than return it else binary search will stop at two neighours of key i.e. find min absolute diff between low and high and return 
				// This won't work take testcase as 1 2 5 10 15 and key=6 it will give 10 instead of 5
        }
}
