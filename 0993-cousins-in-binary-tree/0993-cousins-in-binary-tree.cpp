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
    void dfs(TreeNode* root,unordered_map<int,pair<int,int>>&mp,int parent,int depth)
    {
        if(root==NULL) return;
        mp[root->val]={parent,depth};
        dfs(root->left,mp,root->val,depth+1);
        dfs(root->right,mp,root->val,depth+1);
    }
    bool isCousins(TreeNode* root, int x, int y){
        unordered_map<int,pair<int,int>>mp;
        int depth=0,parent=root->val;
        dfs(root->left,mp,parent,depth+1);
        dfs(root->right,mp,parent,depth+1);
        if((mp[x].first!=mp[y].first) && (mp[x].second==mp[y].second)) return true;
        return false;   
    }
};