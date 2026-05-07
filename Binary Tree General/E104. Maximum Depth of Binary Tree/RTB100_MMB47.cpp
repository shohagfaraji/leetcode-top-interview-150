// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 46.79%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& mxDep, int depth) {
        if (root->left) {
            TreeNode* left = root->left;
            depth++;
            dfs(left, mxDep, depth);
            mxDep = max(mxDep, depth);
            depth--;
        }
        if (root->right) {
            TreeNode* right = root->right;
            depth++;
            dfs(right, mxDep, depth);
            mxDep = max(mxDep, depth);
            depth--;
        }
    }

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int mxDep = 0;
        dfs(root, mxDep, 0);
        
        return mxDep + 1;
    }
};