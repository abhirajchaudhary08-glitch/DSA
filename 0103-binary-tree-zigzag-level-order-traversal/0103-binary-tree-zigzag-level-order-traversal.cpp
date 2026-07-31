class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> row(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=(flag) ? i:(n-i-1);
                row[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};