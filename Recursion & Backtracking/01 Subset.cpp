// https://leetcode.com/problems/subsets/description/

class Solution 
{
    void f_TD(int ind, vector<int>&nums, vector<int> &subset, vector<vector<int>> &ans)
    {
        // base case;
        if(ind == nums.size())
        {
            ans.push_back(subset);
            return ;
        }

        subset.push_back(nums[ind]);
        f_TD(ind+1, nums, subset, ans);

        subset.pop_back();
        f_TD(ind+1, nums, subset, ans);
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int> subset;
        f_TD(0, nums, subset, ans);
        return ans;
    }
};