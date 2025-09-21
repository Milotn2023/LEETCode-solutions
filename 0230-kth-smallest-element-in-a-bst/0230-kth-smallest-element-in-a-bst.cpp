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
void inorder(TreeNode* root,vector<int>&sor){
    if(root==NULL)return;
    inorder(root->left,sor);
    sor.push_back(root->val);
    inorder(root->right,sor);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>sor;
        inorder(root,sor);
        return sor[k-1];
    }
};