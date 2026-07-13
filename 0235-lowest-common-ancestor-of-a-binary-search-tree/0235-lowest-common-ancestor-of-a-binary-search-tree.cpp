class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root == NULL || root == p || root == q) {
            return root;
        }
        
        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // Result
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else { // Both left and right are not null, we found our result
            return root;
        }
    }
    
};