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
    bool isValidBST(TreeNode* root) {
        return validate (root, -1000000001, 1000000001);
    }
    bool validate(TreeNode* root, int mini, int maxi) {
        if (!root) {
            return true;
        }
        if (root -> val >= maxi || root -> val <= mini) {
            return false;
        }
        return (validate(root -> left, mini, root -> val) && validate(root -> right, root -> val, maxi));
    }
};
