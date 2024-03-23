// Print LCS

class Solution 
{
    int f_BU(int n, int m, string &text1, string &text2)
    {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int ind2=0;ind2<=m;ind2++)
            dp[0][ind2] = 0;

        for(int ind1=0;ind1<=n;ind1++)
            dp[ind1][0] = 0;
        
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                if(text1[ind1-1] == text2[ind2-1])
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = (0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]));
            }
        }
        int len = dp[n][m];
        int i = n, j = m;
        string ans(len, '$');
        int index = len-1;
        while(i > 0 && j > 0)
        {
            if(text1[i-1] == text2[j-1])
            {
                ans[index--] = text1[i-1];
                i--, j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        cout << ans << "\n";
        return dp[n][m];
    }

    public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size();
        int m = text2.size();

        return f_BU(n, m, text1, text2);
    }
};