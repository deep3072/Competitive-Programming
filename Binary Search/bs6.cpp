

// Find an element in a nearly sorted array
// Nearly sorted array is a sorted array whose ith index element is on (i-1)th index or ith index or (i+1)th index (any of 3).
// Obs : Apply classic binary search only, just check ith, (i-1)th and (i+1)th index every time, if found return that else do mid-2 or mid+2 accordingly.
#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll find(vector<ll>arr,ll target)
{
        ll n=arr.size();
        ll high=n-1,low=0;
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]==target)
                        return mid;
                else if(mid+1<n && arr[mid+1]==target)
                        return mid+1;
                else if(mid-1>=0 && arr[mid-1]==target)
                        return mid-1;
                else if(arr[mid]>target)
                        high=mid-2;
                else if(arr[mid]<target)
                        low=mid+2;
        }
        return -1;
}

int main()
{                       
        FAST;
        ll testcases=1;
        cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << tt << ": ";
                ll n,i;
                cin >> n;
                vector<ll>arr(n);
                for(i=0;i<n;i++)
                        cin >> arr[i];
                ll target;
                cin >> target;  //Integer to search
                ll ans=find(arr,target);
                if(ans==-1)
                        cout << "Not Found\n";
                else
                        cout << "Element found at index " << ans << "\n";
        }       
}