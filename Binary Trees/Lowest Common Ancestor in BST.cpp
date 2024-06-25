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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        
        if(p->val > q->val){
            swap(p,q);
        }

        if(p->val <= root->val && q->val >= root->val){
            // cout<<"Condition 1"<<endl;
            return root;
        }
        if(p->val <= root->val && q->val <= root->val){
            // cout<<"Condition 2"<<endl;
            return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val >=root->val && q->val >=root->val){
            // cout<<"Condition 3"<<endl;
            return lowestCommonAncestor(root->right,p,q);
        }
        return nullptr;
    }
};
