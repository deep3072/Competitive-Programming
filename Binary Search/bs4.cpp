// Program to find number of times sorted array is rotated.
// Observation: number of times an array is rotated is equal to finding index of minimum element.

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
                if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n]) //if i-1 and i+1 element is > than ith element then min found
                        return mid;
                else if(arr[mid]<arr[n-1])
                        high=mid-1;
                else 
                        low=mid+1;
        }
        return low;
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
                ll ind=find_min(arr);
                cout << "Minimum element is " << arr[ind] << "\n";
                cout << "Array is rotated " << ind << " times\n";
        }       
}
