// https://leetcode.com/problems/combination-sum-ii/description/

class Solution 
{
    void f_TD(int ind, int target, vector<int> &combination, vector<vector<int>>&ans, vector<int> &candidates)
    {
        if(target == 0)
        {
            ans.push_back(combination);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {
            if(candidates[i] > target)
                break;
            if(i > ind && candidates[i] == candidates[i-1])
                continue;
            combination.push_back(candidates[i]);
            f_TD(i+1, target-candidates[i], combination, ans, candidates);
            combination.pop_back();
        }

    }    
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        
        // 1 1 2 5 6 7 10
        vector<int> combination;
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        f_TD(0, target, combination, ans, candidates);
        return ans;
    }
};