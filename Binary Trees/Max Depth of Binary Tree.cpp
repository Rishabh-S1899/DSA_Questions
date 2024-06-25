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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int count=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        cout<<"This is top: "<<q.front()->val<<" ";
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==nullptr){
                count++;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                if(temp->right !=nullptr){
                    q.push(temp->right);
                }
                if(temp->left !=nullptr){
                    q.push(temp->left);
                }
            }
        }
        return count;
    }
};
