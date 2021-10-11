#include<bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int


ll partition(ll arr[],ll l,ll r)
{
        ll i=l-1; // i would be the last index having arr[i] < arr[r]
        for(ll j=l;j<r;j++)
        {
                if(arr[j]<arr[r])
                {
                        i++;
                        swap(arr[i],arr[j]);
                }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
}

void Quicksort(ll arr[],ll l,ll r)
{
        if(l<r)
        {
                int pivot=partition(arr,l,r);
                Quicksort(arr,l,pivot-1);
                Quicksort(arr,pivot,r);
        }
}

void solve()
{
        ll n,i;
        cin >> n;
        ll arr[n];
        for(i=0;i<n;i++)
                cin >> arr[i];
        Quicksort(arr,0,n-1);
        for(i=0;i<n;i++)
                cout << arr[i] << " ";
}

int main()
{   
        FAST;
        ll testcases=1;
        // cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << t << ": ";
                solve();
        }
}