// class Solution {
// public:
//     bool existInTree(TreeNode* root, TreeNode* target){
//         if(root==NULL) return false;
//         if(root==target) return true;
//         return existInTree(root->left,target) || existInTree(root->right,target);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//          if(existInTree(root->left,p) && existInTree(root->left,q)) return lowestCommonAncestor(root->left,p,q);
//         else if(existInTree(root->right,p)==true && existInTree(root->right,q)== true) return lowestCommonAncestor(root->right,p,q);
//         return root;
        
        
//     }
// };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        if (left != nullptr) return left;
        return right;
    }
};