// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 11.39%

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};

        queue<TreeNode*> q[2];
        q[0].push(root);

        vector<int> ret;
        int level = 0;
        TreeNode* temp = nullptr;

        while (!q[0].empty() || !q[1].empty()) {
            while (!q[level & 1].empty()) {
                temp = q[level & 1].front();
                q[level & 1].pop();

                if (temp->left)
                    q[(level + 1) % 2].push(temp->left);

                if (temp->right)
                    q[(level + 1) % 2].push(temp->right);
            }

            ret.emplace_back(temp->val);
            level++;
        }

        return ret;
    }
};
