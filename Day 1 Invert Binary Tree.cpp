/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/


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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root or (!root->left and !root->right)) return root;
        queue<TreeNode *> qu;
        qu.push(root);
        qu.push(NULL);
        while (qu.size() > 1) {
            TreeNode *curr = qu.front();
            qu.pop();
            if (curr == NULL) {
                if (qu.size() == 1 and qu.front() == NULL) break;
                qu.push(NULL);
                continue;
            }
            if (curr->left)
                qu.push(curr->left);
            if (curr->right)
                qu.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};
