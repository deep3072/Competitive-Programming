[Problem](https://leetcode.com/problems/binary-tree-level-order-traversal/) : Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

<details>
<summary>Code</summary>

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
        public:
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
                vector<vector<int>> ans;
                if(!root)
                        return ans;
                queue<TreeNode *> q1;
                q1.push(root);
                while (!q1.empty()) 
                {
                        int len=q1.size();
                        vector<int> level;
                        for(int i=0;i<len;i++) 
                        {
                                TreeNode *current=q1.front();
                                level.push_back(current->val);
                                if(current->left) 
                                        q1.push(current->left);
                                if(current->right) 
                                        q1.push(current->right);
                                q1.pop();
                        }
                        ans.push_back(level);
                }
                return ans;
        }
};
```
</details>

<details>
<summary>Bonus</summary>
        
- [D. Love Rescue](https://codeforces.com/contest/939/problem/D)
        
- [E. Crazy Robot](https://codeforces.com/contest/1613/problem/E)
</details>
