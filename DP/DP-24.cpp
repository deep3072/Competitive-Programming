// https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284

int f_TD(int ind, int N, vector<int>&price, vector<vector<int>>&dp)
{
	if(ind == 0)
	{
		return N*price[0];
	}
	if(dp[ind][N] != -1)
		return dp[ind][N];
	int notTake = 0 + f_TD(ind-1, N, price, dp);
	int take = INT_MIN;
	int rod_length = ind + 1;
	if(rod_length <= N)
		take = price[ind] + f_TD(ind, N - rod_length, price, dp);
	
	return dp[ind][N] = max(take, notTake);

}

int f_BU(int n, vector<int>&price)
{
	vector<vector<int>>dp(n, vector<int>(n+1, 0));
	for(int N=0;N<=n;N++)
		dp[0][N] = N * price[0];
	
	for(int ind=1;ind<n;ind++)
	{
		for(int N=0;N<=n;N++)
		{
			int notTake = 0 + dp[ind-1][N];
			int take = INT_MIN;
			int rod_length = ind + 1;
			if(rod_length <= N)
				take = price[ind] + dp[ind][N - rod_length];
			
			dp[ind][N] = max(take, notTake);
		}
	}
	return dp[n-1][n];
}

int f_BU_SO(int n, vector<int>&price)
{
	vector<int>prev(n+1, 0), curr(n+1, 0);
	for(int N=0;N<=n;N++)
		prev[N] = N * price[0];
	
	for(int ind=1;ind<n;ind++)
	{
		for(int N=0;N<=n;N++)
		{
			int notTake = 0 + prev[N];
			int take = INT_MIN;
			int rod_length = ind + 1;
			if(rod_length <= N)
				take = price[ind] + curr[N - rod_length];
			
			curr[N] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[n];
}

int f_BU_SO_2(int n, vector<int>&price)
{
	vector<int>prev(n+1, 0);
	for(int N=0;N<=n;N++)
		prev[N] = N * price[0];
	
	for(int ind=1;ind<n;ind++)
	{
		for(int N=0;N<=n;N++)
		{
			int notTake = 0 + prev[N];
			int take = INT_MIN;
			int rod_length = ind + 1;
			if(rod_length <= N)
				take = price[ind] + prev[N - rod_length];
			
			prev[N] = max(take, notTake);
		}
	}
	return prev[n];
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	// vector<vector<int>>dp(n, vector<int>(n+1, -1));
	// return f_TD(n-1, n, price, dp);

	// return f_BU(n, price);

	// return f_BU_SO(n, price);

	return f_BU_SO_2(n, price);
}
