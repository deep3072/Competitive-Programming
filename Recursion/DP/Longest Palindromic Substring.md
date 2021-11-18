[Problem](https://leetcode.com/problems/longest-palindromic-substring/) : Given a string s, return the longest palindromic substring in s.

<details>
<summary>Code</summary>

```
class Solution 
{
        public:
        string longestPalindrome(string s)
        {
                // Time : O(n^2);
                int i,j;
                int n=s.size();
                int dp[1000+1][1000+1]={0};
                // dp[i][j] represent 1 if string of length i ending at index j is palindrome
                // Otherwise 0;
                for(i=0;i<n+1;i++)
                {
                        // base case : strings of length 1 or 0 ending at any index would always be a palindrome;
                        dp[0][i]=1;
                        dp[1][i]=1;
                }
                int mx_len=1;
                string ans;
                int st=0,end=1;
                for(i=2;i<=n;i++)
                {
                        for(j=i;j<=n;j++)
                        {
                                
                                if(dp[i-2][j-1] && s[j-1] == s[j-i])
                                {
                                        // So
                                        // string of length i ending at index j is palindrome
                                        int len=i;
                                        if(len > mx_len)
                                        {
                                                st=j-i;
                                                end=j;
                                                mx_len=i;
                                        }
                                        dp[i][j]=1;
                                }
                        }
                }
                for(i=st;i<end;i++)
                        ans.push_back(s[i]);
                return ans;
        }
};
```
</details>

<details>
<summary>Bonus</summary>
        
[D. Maximum Sum of Products](https://codeforces.com/problemset/problem/1519/D)
</details>
