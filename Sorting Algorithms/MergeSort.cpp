#include<bits/stdc++.h>

using namespace std;


#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

void merge(ll arr[],ll l,ll mid,ll r)
{
        // l to mid elements in arr1
        // mid+1 to r elements in arr2
        ll n1 = mid - l + 1;
        ll n2 = r - mid;
        
        ll arr1[n1], arr2[n2];
        for(int i=0;i<n1;i++)
                arr1[i] = arr[l+i];
        
        for(int i=0;i<n2;i++)
                arr2[i] = arr[mid+i+1];
        
        // arr1 and arr2 are internally sorted, we just merge them to make sorted array
        ll i = 0;
        ll j =0, index=l;
        while(i<n1 && j<n2)
        {
                if(arr1[i] <= arr2[j])
                        arr[index++] = arr1[i++];
                else
                        arr[index++] = arr2[j++];
        }
        
        while(i<n1)
                arr[index++] = arr1[i++];
        
        while(j<n2)
                arr[index++] = arr2[j++];
        
}

void mergeSort(ll arr[],ll l, ll r)
{
        if(l<r)
        {
                ll mid = (l+r)/2;
                mergeSort(arr,l,mid);
                mergeSort(arr,mid+1,r);
                
                merge(arr,l,mid,r);
        }
}
void solve()
{
        ll n,i;
        cin >> n;
        ll arr[n];
        for(i=0;i<n;i++)
                cin >> arr[i];
        
        mergeSort(arr,0,n-1);
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