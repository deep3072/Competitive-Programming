[Problem](https://leetcode.com/problems/longest-increasing-subsequence/) : Given an integer array arr, return the length of the longest strictly increasing subsequence.

<details>
<summary>Code</summary>

```
class Solution 
{
        public:
        int lengthOfLIS(vector<int>& arr) 
        {
                // Greedy + Binary Search;
                // Time : O(nlogn)
                int i;
                int n=arr.size();
                vector<int>v1; 
                v1.push_back(arr[0]);
                for(i=1;i<n;i++)
                {
                        if(arr[i]>v1.back())
                                v1.push_back(arr[i]);
                        else{
                                // find the smallest number >= arr[i] in v1
                                // Replace it with arr[i];
                                int low=0,high=v1.size()-1,ind=0;
                                while(low<=high)
                                {
                                        int mid=low+(high-low)/2;
                                        if(v1[mid]==arr[i])
                                        {
                                                ind=mid;
                                                break;
                                        }
                                        else if(v1[mid]>arr[i])
                                        {
                                                ind=mid;
                                                high=mid-1;
                                        }
                                        else
                                                low=mid+1;
                                }
                                v1[ind]=arr[i];
                        }
                }
                return v1.size();
        }
};
```
</details>

<details>
<summary>DP ?🤔</summary>
        
[Don't Click](https://github.com/deep3072/Competitive-Programming/blob/master/Recursion/DP/Longest%20Increasing%20Subsequence.md)
</details>
        
<details>
<summary>Bonus</summary>
        
- [Longest Monotonically Nondecreasing Sequence](https://www.spoj.com/problems/LMIS/)
</details>


