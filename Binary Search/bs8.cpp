
// Find Ceil of an element in a Sorted array
// Ceil of the element means print minimum element which is greater than equal to given element.
#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll find_ceil(vector<ll>arr,ll target)
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
                cin >> target;
                ll ans=find_ceil(arr,target);
                if(ans==INT_MAX)
                        cout << "Ceil not found";
                else
                        cout << "Ceil of " << target << " is " << ans << "\n";
        }       
}
