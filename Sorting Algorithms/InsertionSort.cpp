#include<bits/stdc++.h>

using namespace std;


#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

void InsertionSort(ll arr[],ll n)
{   
        for(int i=1;i<n;i++)
        {
            int key = arr[i];
            // place arr[i] to it's correct position in left subarray
            for(int j=i-1;j>=0;j--)
            {
                if(arr[j] > key)
                {
                    arr[j+1] = arr[j];
                    arr[j] = key;
                }
                else
                    break;
            }
        }
}

void solve()
{
        ll n,i;
        cin >> n;
        ll arr[n];
        for(i=0;i<n;i++)
                cin >> arr[i];
        
        InsertionSort(arr,n);
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