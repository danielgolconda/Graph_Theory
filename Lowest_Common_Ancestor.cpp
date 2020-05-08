/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        
        map <TreeNode*,int> lev;
        map <TreeNode*,TreeNode*> par;
        queue <TreeNode*> q;
        q.push(root);
        lev[root] = 0;
        par[root] = new TreeNode(-1);
        // Step - 1 Finding the levels of each node
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                TreeNode* f = q.front();
                q.pop();
                if(f->left)
                {
                    lev[f->left] = lev[f] + 1;
                    par[f->left] = f;
                    q.push(f->left);
                }
                if(f->right)
                {
                    lev[f->right] = lev[f] + 1;
                    par[f->right] = f;
                    q.push(f->right);
                }
            }
        }
        if(lev[a] <= lev[b])
        {
            int d = lev[b] - lev[a];
            // Making the levels equal by pushing the deeper level up
            while(d > 0)
            {
                b = par[b];
                d--;
            }
            // Now if one node is in the subtree of another subtree
            if(a == b) return a;
            // moving both nodes up and checking for equality
            while(par[a] != par[b])
            {
                a = par[a];
                b = par[b];
            }
        }
        else
        {
            int d = lev[a] - lev[b];
            while(d > 0)
            {
                a = par[a];
                d--;
            }
            if(a == b) return a;
            while(par[a] != par[b])
            {
                a = par[a];
                b = par[b];
            }
        }
        return par[b];
    }
};
