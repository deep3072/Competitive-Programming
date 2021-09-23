// Simple use of Comparator function

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define all(v1) v1.begin(),v1.end()

bool cmp_without_inbuilt_sort(int x,int y)
{
        if(x>y)
                return 1;
        return 0;
}

bool cmp(int x,int y)
{
        //if(x>y)
        //        return 0;
        //return 1;
		
		//Another way
		return (x<y);  //for decreasing order
}
void solve()
{
        int i,j;
        vector<int>a={3,2,1,5,4};
        int n=5;
        // for(i=0;i<n;i++)
        // {
        //         for(j=i+1;j<n;j++)
        //         {
        //                 if(cmp_without_inbuilt_sort(a[i],a[j]))
        //                         swap(a[i],a[j]);
        //         }
        // }
        sort(all(a),cmp);
        for(i=0;i<n;i++)
                cout << a[i] << " ";
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