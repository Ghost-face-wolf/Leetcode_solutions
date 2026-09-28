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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int maxsum=INT_MIN;
        int bestlevel=1,currentlevel=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            int currentlevelsum=0;
            for(int i=0;i<levelsize;++i){
                TreeNode* curr=q.front();
                q.pop();
                currentlevelsum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            if(currentlevelsum>maxsum){
                maxsum=currentlevelsum;
                bestlevel=currentlevel;
            }
            currentlevel++;

        }
        return bestlevel;
    }
};