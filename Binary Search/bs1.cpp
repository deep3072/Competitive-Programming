// WAP to find an element in a sorted array

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

ll classic_bs(vector<ll>arr, ll target)
{
        ll high=arr.size()-1,low=0;
        while(low<=high)
        {
                ll mid=low+(high-low)/2;
                if(arr[mid]==target)
                        return mid;
                else if(arr[mid]<target)
                        low=mid+1;
                else
                        high=mid-1;
        }
        return -1; // Element not found;
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
                ll ans=classic_bs(arr,target);
                if(ans==-1)
                        cout << "Target element not found\n";
                else
                        cout << "Target element found at index " << ans << "\n";   
        }
}
