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
    int diacalculator(TreeNode* node, int &dia){
        int curr=INT_MIN;
        if(!node){
            return 0;
        }
        diacalculator(node->left,dia);
        diacalculator(node->right,dia);
        curr=maxDepth(node->left)+maxDepth(node->right);
        if(curr>dia){
            dia=curr;
        }
        // dia=max(diacalculator(node->left,dia),diacalculator(node->right,dia));
        return dia;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int dia=INT_MIN;
        return diacalculator(root,dia);
    }
};
