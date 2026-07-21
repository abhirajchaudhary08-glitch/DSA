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
  int mx(TreeNode* root,int &ans){
        int a =0;
        if(root->left) a=mx(root->left,ans);
        int b =0;
        if(root->right) b=mx(root->right,ans);
        a=max(a,b);
        if(root->val>=a){
            ans++;
        }
        a = max(root->val,a);
        return a;
    }
class Solution {
public:
   
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        mx(root,cnt);
        return cnt;
    }
};