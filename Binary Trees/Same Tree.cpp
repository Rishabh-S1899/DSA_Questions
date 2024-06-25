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
    bool isSameNode(TreeNode* p, TreeNode* q){
        //BaseCase
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr && q!=nullptr){
            return false;
        }
        if(q==nullptr && p!=nullptr){
            return false;
        }
        bool leftpar=isSameNode(p->left,q->left);
        bool rightpar=isSameNode(p->right,q->right);
        bool val= p->val==q->val;
        if(leftpar && rightpar && val){
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameNode(p,q);
    }
};
