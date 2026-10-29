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
private:
    bool checkMirror(TreeNode* leftSide, TreeNode* rightSide) {
        if (!leftSide && !rightSide) return true;
        if (!leftSide || !rightSide) return false;
        
        return (leftSide->val == rightSide->val) && 
               checkMirror(leftSide->left, rightSide->right) && 
               checkMirror(leftSide->right, rightSide->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return checkMirror(root->left, root->right);
    }
};
