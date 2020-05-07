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
        if(root == NULL)
        {
            return NULL;
        }
        unordered_map <TreeNode*,pair<int,TreeNode*>> mp; // mp[Node] = {level,parent}
        //TreeNode* o = new TreeNode(-1);
        queue <TreeNode*> q;
        q.push(root);
        mp[root] = {0,new TreeNode(-1)};
        int lev = 0;
        while(!q.empty())
        {
            lev++;
            int k =q.size();
            while(k--)
            {
                TreeNode* f = q.front();
                q.pop();
                if(f->left)
                {
                    mp[f->left] = {lev,f};
                    q.push(f->left);
                }
                if(f->right)
                {
                    mp[f->right] = {lev,f};
                    q.push(f->right);
                }
            }
        }
        pair<int,TreeNode*> ta = mp[a];
        pair<int,TreeNode*> tb = mp[b];
        if(ta.first <= tb.first)
        {
            ta = mp[a];
            tb = mp[b];
            int dist = tb.first-ta.first;
            while(dist > 0)
            {
                tb = mp[b];
                b = tb.second;
                dist--;
            }
            if(a == b) return a;
            while(ta.second != tb.second)
            {
                ta = mp[a];
                tb = mp[b];
                a = ta.second;
                b = tb.second;
            }
        }
        else
        {
            
            ta = mp[a];
            tb = mp[b];
            int dist = ta.first-tb.first;
            while(dist > 0)
            {
                ta = mp[a];
                a = ta.second;
                dist--;
            }
            if(a == b) return a;
            while(ta.second != tb.second)
            {
                ta = mp[a];
                tb = mp[b];
                a = ta.second;
                b = tb.second;
            }   
        }
        return tb.second;
    }
};
