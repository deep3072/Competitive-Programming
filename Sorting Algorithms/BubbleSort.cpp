#include<bits/stdc++.h>

using namespace std;


#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

void bubbleSort(ll arr[],ll n)
{
        for(int i=0;i<n-1;i++)
        {
                int flag = 0;
                // Last i elements are already in place
                for(int j=0;j<n-i-1;j++)
                {
                    if(arr[j] > arr[j+1])
                    {
                        swap(arr[j],arr[j+1]);
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    // no swaps occured hence array already sorted
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
        
        bubbleSort(arr,n);
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