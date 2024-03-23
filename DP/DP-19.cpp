// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 

int f_TD(int ind, vector<int> &weight, vector<int> &value, int wt, vector<vector<int>>&dp)
{
	if(ind == 0)
	{
		if(weight[ind] <= wt)
			return value[ind];
		return 0;
	}
	if(dp[ind][wt] != -1)
		return dp[ind][wt];
	int notPick = 0 + f_TD(ind-1, weight, value, wt, dp);
	int pick = INT_MIN;
	if(weight[ind] <= wt)
		pick = value[ind] + f_TD(ind-1, weight, value, wt-weight[ind], dp);
	return dp[ind][wt] = max(pick, notPick);
}

int f_BU(int n, vector<int> &weight, vector<int> &value, int maxWeight)
{
	vector<vector<int>>dp(n, vector<int>(maxWeight + 1, 0));
	for(int wt = weight[0];wt<=maxWeight;wt++)
		dp[0][wt] = value[0];
	
	for(int ind=1;ind<n;ind++)
	{
		for(int wt=0;wt<=maxWeight;wt++)
		{
			int notPick = 0 + dp[ind-1][wt];
			int pick = INT_MIN;
			if(weight[ind] <= wt)
				pick = value[ind] + dp[ind-1][wt-weight[ind]];
			
			dp[ind][wt] = max(pick, notPick);
		}
	}
	return dp[n-1][maxWeight];
}

int f_BU_SO(int n, vector<int> &weight, vector<int> &value, int maxWeight)
{
	vector<int>prev(maxWeight+1, 0);
	for(int wt = weight[0];wt<=maxWeight;wt++)
		prev[wt] = value[0];
	
	for(int ind=1;ind<n;ind++)
	{
		for(int wt=maxWeight;wt>=0;wt--)
		{
			int notPick = 0 + prev[wt];
			int pick = INT_MIN;
			if(weight[ind] <= wt)
				pick = value[ind] + prev[wt-weight[ind]];
			
			prev[wt] = max(pick, notPick);
		}
	}
	return prev[maxWeight];
}

int f_BU_SO_2(int n, vector<int> &weight, vector<int> &value, int maxWeight)
{
	vector<int>prev(maxWeight+1, 0), curr(maxWeight+1, 0);
	for(int wt = weight[0];wt<=maxWeight;wt++)
		prev[wt] = value[0];
	
	for(int ind=1;ind<n;ind++)
	{
		for(int wt=0;wt<=maxWeight;wt++)
		{
			int notPick = 0 + prev[wt];
			int pick = INT_MIN;
			if(weight[ind] <= wt)
				pick = value[ind] + prev[wt-weight[ind]];
			
			curr[wt] = max(pick, notPick);
		}
		prev = curr;
	}
	return prev[maxWeight];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// vector<vector<int>>dp(n+1, vector<int>(maxWeight+1, -1));
	// return f_TD(n-1, weight, value, maxWeight, dp);

	// return f_BU(n, weight, value, maxWeight);

	// return f_BU_SO(n, weight, value, maxWeight);

	return f_BU_SO_2(n, weight, value, maxWeight);
}