
// Longest Palindromic Substring;
// Problem link : https://leetcode.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>
//--------------------------------------------------------------------------------------------------------------------------

void solve()
{
        // Time : O(n^2);
        // Space : O(n^2);
        // Standard Dynamic Programming approach
        int i,j;
        string s;
        cin >> s;
        int n=s.size();
        int dp[n+1][n+1];
        for(i=0;i<=n;i++)
                for(j=0;j<=n;j++)
                        dp[i][j]=0;
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
        int st=0,end=1; // Starting and ending index of final ans string ;
        for(i=2;i<=n;i++)
        {
                for(j=i;j<=n;j++)
                {
                        if(dp[i-2][j-1] && s[j-1] == s[j-i])
                        {
                                // cout << i << " " << j << "\n";
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
        cout << ans << "\n";
}

int main()
{   
        // FAST;
        int testcases=1;
        cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << t << ": ";
                solve();
        }
}

// Video Editorial : https://www.youtube.com/watch?v=OjaUemQyDmw

