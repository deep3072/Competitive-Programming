// https://leetcode.com/problems/subsets-ii/description/

class Solution 
{
    void f_TD(int ind, vector<int>&subset, vector<vector<int>>&ans, vector<int>&nums)
    {
        ans.push_back(subset);
        for(int i=ind;i<nums.size();i++){

            if(i != ind && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            f_TD(i+1, subset, ans, nums);
            subset.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>subset;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        f_TD(0, subset, ans, nums);
        return ans;
    }
};