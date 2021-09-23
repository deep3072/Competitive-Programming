// WAP to find first occurence of a element in a sorted array.
// In a similar way program for last occurence can be written.

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll first_occu(vector<ll>arr, ll target)
{
        ll high=arr.size()-1,low=0,res=arr.size();
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]==target)
                {
                        high=mid-1;
                        res=min(res,mid);
                }
                else if(arr[mid]<target)
                        low=mid+1;
                else
                        high=mid-1;
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
                ll target;
                cin >> target;  //Integer to search
                ll ans=first_occu(arr,target);
                if(ans==n)
                        cout << "Target element not found\n";
                else
                        cout << "First occurence of target element is at index " << ans << "\n";   
        }
}
