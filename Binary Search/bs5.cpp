
// Program to find an element in a rotated sorted array.
// Obs: Search min element in rotated sorted array then apply classic binary search in one of the two halfs of the array.

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll find_min(vector<ll>arr)
{
        ll high=arr.size()-1,low=0;
        ll n=arr.size();
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n])
                        return mid;
                else if(arr[mid]<arr[n-1])
                        high=mid-1;
                else 
                        low=mid+1;
        }
        return low;
}

ll classic_bs(vector<ll>arr, ll start,ll end,ll target)
{
        ll high=end,low=start;
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                // cout << low << " " << mid << " " << high << " " << arr[mid] << "\n";
                if(arr[mid]==target)
                        return mid;
                else if(arr[mid]<target)
                        low=mid+1;
                else
                        high=mid-1;
        }
        return -1;
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
                ll min=find_min(arr);
                cout << "Minimum element is " << arr[min] << "\n";
                ll ans;
                if(arr[n-1]<target)
                        ans=classic_bs(arr,0,min-1,target);
                else 
                        ans=classic_bs(arr,min,n-1,target);
                if(ans==-1) 
                        cout << "Element Not Found";
                else
                        cout << "Element found at index " << ans << "\n"; //Print index
        }       
}