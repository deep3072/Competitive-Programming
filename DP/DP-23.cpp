// https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?leftPanelTab=0

int f_TD(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>&dp)
{
    if(ind == 0)
    {
        return (w/weight[0])*profit[0];
    }
    if(dp[ind][w] != -1)
        return dp[ind][w];
    int notTake = f_TD(ind-1, w, profit, weight, dp);
    int take = 0;

    if(weight[ind] <= w)
        take = profit[ind] + f_TD(ind, w-weight[ind], profit, weight, dp);
    
    return dp[ind][w] = max(take, notTake);
}

int f_BU(int n, int totalwt, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n, vector<int>(totalwt+1, 0));
    for(int w=0;w<=totalwt;w++)
        dp[0][w] = (w/weight[0])*profit[0];

    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=totalwt;w++)
        {
            int notTake = dp[ind-1][w];
            int take = 0;

            if(weight[ind] <= w)
                take = profit[ind] + dp[ind][w-weight[ind]];
            
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n-1][totalwt];
}

int f_BU_SO(int n, int totalwt, vector<int> &profit, vector<int> &weight)
{
    vector<int>prev(totalwt+1, 0), curr(totalwt+1, 0);
    for(int w=0;w<=totalwt;w++)
        prev[w] = (w/weight[0])*profit[0];

    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=totalwt;w++)
        {
            int notTake = prev[w];
            int take = 0;

            if(weight[ind] <= w)
                take = profit[ind] + curr[w-weight[ind]];
            
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[totalwt];
}

int f_BU_SO_2(int n, int totalwt, vector<int> &profit, vector<int> &weight)
{
    vector<int>prev(totalwt+1, 0);
    for(int w=0;w<=totalwt;w++)
        prev[w] = (w/weight[0])*profit[0];

    for(int ind=1;ind<n;ind++)
    {
        for(int w=0;w<=totalwt;w++)
        {
            int notTake = prev[w];
            int take = 0;

            if(weight[ind] <= w)
                take = profit[ind] + prev[w-weight[ind]];
            
            prev[w] = max(take, notTake);
        }
    }
    return prev[totalwt];
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>>dp(n, vector<int>(w+1, -1));
    // return f_TD(n-1, w, profit, weight, dp);

    // return f_BU(n, w, profit, weight);

    // return f_BU_SO(n, w, profit, weight);

    return f_BU_SO_2(n, w, profit, weight);
}