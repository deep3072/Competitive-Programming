
// WAP to find position of an element in an infinite sorted array

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

int main()
{                       
        FAST;
        ll testcases=1;
        cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << tt << ": ";
                ll low=0,high=1;
                while(1)
                {
                        if(arr[high]>=target)
                        {
                                Apply classic_binary search in interval low to high and find index;
                                break;
                        }
                        else
                        {
                                low=high;
                                high*=2;
                        }
                }
        }
}
