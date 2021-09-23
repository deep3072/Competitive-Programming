// WAP to find count of an element in a sorted array.

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

ll last_occu(vector<ll>arr, ll target)
{
        ll high=arr.size()-1,low=0,res=-1;
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]==target)
                {
                        low=mid+1;
                        res=max(res,mid);
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
                ll ans=last_occu(arr,target)-first_occu(arr,target)+1;
                cout << "Count of target element is " << ans << "\n";   
        }
}