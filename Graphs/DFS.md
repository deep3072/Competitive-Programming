[Problem](https://leetcode.com/problems/path-sum/) : Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

<details>
<summary>Code</summary>
        
```
class Solution 
{
        public:
        bool hasPathSum(TreeNode* root, int targetSum)
        {
                if(root == NULL)
                        return false;
                if(root->left == NULL && root->right == NULL && root->val - targetSum == 0)
                        return true;
        
                bool left = hasPathSum(root->left,targetSum - root->val);
                bool right = hasPathSum(root->right,targetSum - root->val);
        
                return left || right;
        }
};
```
        
</details>

class Solution 
{
        public:
        bool hasPathSum(TreeNode* root, int sum) 
        {
                //iterative solution DFS
                if(!root)
                        return false;
                stack<TreeNode*> treeStack;
                stack<int> sumStack;
                treeStack.push(root);
                sumStack.push(sum);
                while(!treeStack.empty())
                {
                        auto node = treeStack.top();
                        treeStack.pop();
                        auto sumnode = sumStack.top();
                        sumStack.pop();
                        if(node->left == NULL && node->right == NULL && node->val==sumnode)
                                return true;
                        if(node->left!=NULL)
                        {
                                treeStack.push(node->left);
                                sumStack.push(sumnode - node->val);
                        }
                        if(node->right!=NULL)
                        {
                                treeStack.push(node->right);
                                sumStack.push(sumnode - node->val);
                        }
                }
                return false;
        }
};