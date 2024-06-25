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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
public:
    pair<bool,int> isBalancedquick(TreeNode* root){
        if(!root){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=isBalancedquick(root->left);
        pair<bool,int> right=isBalancedquick(root->right);
        bool l=left.first;
        bool r=right.first;
        bool h=abs(left.second-right.second) <=1;
        if(l && r && h){
            pair<bool,int> ans=make_pair(true,0);
            return ans;
        }
        pair<bool,int> ans=make_pair(false,0);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedquick(root).first;
    }
};
