[Problem](https://leetcode.com/problems/longest-increasing-subsequence/) : Given an integer array arr, return the length of the longest strictly increasing subsequence.

<details>
<summary>Code</summary>

```
class Solution 
{
        public:
        int lengthOfLIS(vector<int>& arr) 
        {
                // Time complexity : O(N^2) 

                int i,n=arr.size(),j;
                int dp[n];
                // dp[i] : LIS having ith index as last index in subsequence;

		// Req ans : max(dp[0],dp[1]...,dp[n-1]); 
                
                // Base Case
                dp[0]=1;
                
		// Recurrence Relation
		//dp[i]=max(dp[0],dp[1]..,dp[j])+1 --> iff j<i and arr[j] < arr[i]
                int ans=1;
                for(i=1;i<n;i++)
                {
                        int mx=0;
                        for(j=0;j<i;j++)
                        {
                                if(dp[j]>mx && arr[j]<arr[i])
                                        mx=dp[j];
                        }
                        dp[i]=mx+1;
                        ans=max(ans,dp[i]);
                }
                return ans;
        }
};
```
</details>

<details>
<summary>Optimal Solution🤔</summary>
Think about Greedy + Binary Search in O(NlogN)
</details>
