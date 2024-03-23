// Find nth fibonacci number
#include<bits/stdc++.h>

int fibo_TD(int n, vector<int>&dp) // TD : top Down
{
        if(n <= 1)
                return n;
        if(dp[n] != -1)
                return dp[n];
        // int last = fibo_TD(n-1, dp);
        // int slast = fibo_TD(n-2, dp);
        // dp[n] = last + slast;
        // return dp[n];
	return dp[n] = fibo_TD(n-1, dp) + fibo_TD(n-2, dp);
}

int fibo_BU(int n, vector<int>&dp)
{
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++)
                dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
}

int main()
{
        int n;
        cin >> n;
        vector<int>dp(n+1, -1);
        // cout << fibo_TD(n, dp) << "\n";
        cout << fibo_BU(n, dp) << "\n";
}
