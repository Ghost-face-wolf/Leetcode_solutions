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
    int matchingnodecount=0;
    pair<int,int> dfs(TreeNode*root){
        if(!root){
            return{0,0};
        }
        auto [leftsum,leftcount]=dfs(root->left);
        auto [rightsum,rightcount]=dfs(root->right);
        int currentsum=root->val+leftsum+rightsum;
        int currentcount=1+rightcount+leftcount;
        if(root->val==currentsum/currentcount){
            matchingnodecount++;
        }
        return {currentsum, currentcount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        matchingnodecount=0;
        dfs(root);
        return matchingnodecount;
        
    }
};