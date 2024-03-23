// Print LIS -> Tabulation


class Solution 
{
    int f_BU_2_printLIS(int n, vector<int>&nums)
    {
        vector<int>dp(n, 1), prevIndex(n, 0); // prevIndex[i] : prev index of current nums[i] in LIS;
        int ans = 0, lastIndex = 0;
        for(int i=0;i<n;i++)
        {
            prevIndex[i] = i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    prevIndex[i] = prev;
                }
            }
            if(dp[i] > ans)
            {
                lastIndex = i;
                ans = dp[i];
            }
        }
        vector<int>lis;
        lis.push_back(nums[lastIndex]);
        while(prevIndex[lastIndex] != lastIndex)
        {
            lastIndex = prevIndex[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        for(int i=0;i<lis.size();i++)
            cout << lis[i] << " ";
        return ans;
    }
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();

        return f_BU_2_printLIS(n, nums);
    }
};