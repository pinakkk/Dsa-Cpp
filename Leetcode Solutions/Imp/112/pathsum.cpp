class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false; // Base case: if root is null, return false
    if (!root->left && !root->right) return root->val == targetSum; // Leaf node
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

};