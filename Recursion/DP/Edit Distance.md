[Problem](https://leetcode.com/problems/edit-distance/) : Given two strings ```word1``` and ```word2```, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
<ul>
        <li>Insert a character</li>
        <li>Delete a character</li>
        <li>Replace a character</li>
</ul>


<details>
<summary>Code</summary>

```
class Solution 
{
        public:
        int minDistance(string s1, string s2) 
        {
                int i,j;
                int n1=s1.size();
                int n2=s2.size();
                
                int dp[n1+1][n2+1];
                // dp[i][j] is min num of operations req to convert s1 ending at ith index to s2 ending at jth index;
                // our req ans=dp[n1][n2];
                
                //Base case
                // if s1 or s2 size is 0
                for(j=0;j<=n2;j++) // s1=0
                {
                        dp[0][j]=j;
                }
                for(i=0;i<=n1;i++) // s2=0
                {
                        dp[i][0]=i;
                }
                
                //Recurrence relation
                // s1[i-1]==s2[j-1] : dp[i][j]+=dp[i-1][j-1]
                // s1[i-1]!=s2[j-1] : dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})
                for(i=1;i<=n1;i++)
                {
                        for(j=1;j<=n2;j++)
                        {
                                if(s1[i-1]==s2[j-1])
                                        dp[i][j]=dp[i-1][j-1];
                                else
                                        dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                        }
                }
                return dp[n1][n2];
        }
};
```
</details>
