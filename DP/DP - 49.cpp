// Matrix Chain Multiplication

#include <bits/stdc++.h> 

int f_TD(int i, int j, vector<int>&arr, vector<vector<int>> &dp)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mn = 1e9;
    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + f_TD(i, k, arr, dp) + f_TD(k+1, j, arr, dp);
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}

int f_BU(vector<int> &arr, int n)
{
    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int mn = 1e9;
            for(int k=i;k<j;k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mn = min(mn, steps);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // vector<vector<int>>dp(N, vector<int>(N, -1));
    // return f_TD(1, N-1, arr, dp);

    return f_BU(arr, N);
}