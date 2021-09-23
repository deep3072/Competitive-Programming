
// Find Floor of an element in a Sorted array
// Floor of an element we mean if given element is present in array print the element else print the maximum element which is smaller than given element

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll find_floor(vector<ll>arr,ll target)
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
                cin >> target; // Floor of this element to be search
                ll ans=find_floor(arr,target);
                if(ans==-1)
                        cout << "Floor not found";
                else
                        cout << "Floor of " << target << " is " << ans << "\n";
        }       
}
