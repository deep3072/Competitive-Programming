// Problem link : https://leetcode.com/problems/longest-common-subsequence/

class Solution 
{
        public:
        int longestCommonSubsequence(string s1, string s2) 
        {
                int n1=s1.size();
                int n2=s2.size();
                int i,j;
                
                int dp[n1+1][n2+1];
                // dp[i][j] = LCS till ith index in s1 and jth index in s2;
                // req ans = dp[n1][n2];
                
                // Base case
                for(i=0;i<=n1;i++)
                {
                        for(j=0;j<=n2;j++)
                               dp[i][j]=0;
                }
                // recurrence relation;
                // if s1[i] == s2[j] then dp[i][j] += dp[i-1][j-1]+1;
                for(i=1;i<=n1;i++)
                {
                        for(j=1;j<=n2;j++)
                        {
                                if(s1[i-1]==s2[j-1])
                                        dp[i][j] += dp[i-1][j-1]+1;
                                else
                                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                        }
                }
                return dp[n1][n2];
        }
};