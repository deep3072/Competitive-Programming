//WAP to find index of Peak element

#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int

int findPeakElement(vector<int>& nums) 
{
        int n=nums.size();
        if(n==1)
                return 0;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
                int mid=low+(high-low)/2;
                if(mid==0)
                {
                        if(nums[mid]>nums[mid+1])
                                return mid;
                        else
                                return mid+1;
                }
                else if(mid==n-1)
                {
                        if(nums[mid]>nums[mid-1])
                                return mid;
                        else
                                return mid-1;
                }
                else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                        return mid;
                else if(nums[mid]<nums[mid+1])
                        low=mid+1;
                else high=mid-1;

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
                vector<int>arr(n);
                for(i=0;i<n;i++)
                        cin >> arr[i];
                int ans=findPeakElement(arr);
                cout << "Index of Peak Element is " << ans << "\n";
        }
}