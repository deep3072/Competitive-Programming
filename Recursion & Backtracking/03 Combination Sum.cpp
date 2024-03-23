// https://leetcode.com/problems/combination-sum/description/

class Solution 
{
    void f_TD(int ind, int target, vector<int>&combination, vector<vector<int>>&ans, vector<int>&candidates)
    {
        if(target == 0)
        {
            ans.push_back(combination);
            return ;
        }
        if(ind == candidates.size())
        {
            return ;
        }
        f_TD(ind+1, target, combination, ans, candidates);

        if(candidates[ind] <= target)
        {
            combination.push_back(candidates[ind]);
            f_TD(ind, target-candidates[ind], combination, ans, candidates);
            combination.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>combination;
        vector<vector<int>>ans;
        f_TD(0, target, combination, ans, candidates);
        return ans;
    }
};
