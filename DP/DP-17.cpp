#define mod 1000000007

int f_TD(int ind, int sum, vector<int>&nums, vector<vector<int>>&dp)
{
	if(ind == 0)
	{
		if(sum == 0 && nums[0] == 0)
			return 2;
		if(sum == 0 || sum == nums[0])
			return 1;
		return 0;
	}

	if(dp[ind][sum] != -1)
		return dp[ind][sum];

	int notPick = f_TD(ind-1, sum, nums, dp);
	int pick = 0;
	if(nums[ind] <= sum) pick = f_TD(ind-1, sum - nums[ind], nums, dp);

	return (dp[ind][sum] = (notPick%mod + pick%mod)%mod);
}

int f_BU(int n, int k, vector<int>&nums)
{
	vector<vector<int>>dp(n, vector<int>(k+1, 0));
	
    if(nums[0] == 0)
        dp[0][0] = 2;
    else dp[0][0] = 1;

	if(nums[0] != 0 && nums[0] <= k) dp[0][nums[0]] = 1;
	
	for(int ind=1;ind<n;ind++)
	{
		for(int sum=0;sum<=k;sum++)
		{
			int notPick = dp[ind-1][sum];
			int pick = 0;
			if(nums[ind] <= sum) pick = dp[ind-1][sum - nums[ind]];

			dp[ind][sum] = (notPick + pick)%mod;
		}
	}

	return dp[n-1][k];
}

int f_BU_SO(int n, int k, vector<int>&nums)
{
	vector<int>cur(k+1, 0), prev(k+1, 0);
	if(nums[0] == 0)
        prev[0] = 2;
    else prev[0] = 1;

	if(nums[0] != 0 && nums[0] <= k) prev[nums[0]] = 1;
	
	for(int ind=1;ind<n;ind++)
	{
		for(int sum=0;sum<=k;sum++)
		{
			int notPick = prev[sum];
			int pick = 0;
			if(nums[ind] <= sum) pick = prev[sum - nums[ind]];

			cur[sum] = (notPick + pick)%mod;
		}
		prev = cur;
	}

	return prev[k];
}

int findWays(vector<int>& nums, int k)
{
	int n = nums.size();

	vector<vector<int>>dp(n, vector<int>(k+1, -1));
	return f_TD(n-1, k, nums, dp);

	// return f_BU(n, k, nums);

	// return f_BU_SO(n, k, nums);
}
