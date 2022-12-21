#include<bits/stdc++.h>

using namespace std;


#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

void selectionSort(ll arr[],ll n)
{
    for(int i=0;i<n;i++)
    {
        int min_value = arr[i];
        int min_index = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < min_value)
            {
                min_index = j;
                min_value = arr[j];
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

void solve()
{
        // Unstable 
        ll n,i;
        cin >> n;
        ll arr[n];
        for(i=0;i<n;i++)
                cin >> arr[i];
        
        selectionSort(arr,n);
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