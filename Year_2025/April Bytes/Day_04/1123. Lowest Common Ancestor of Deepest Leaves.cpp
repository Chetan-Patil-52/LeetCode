//Approach-2 (Using 1 Pass Solution)
//T.C : O(n)
//S.C : O(maxDepth) System stack space
class Solution {
public:
    pair<int, TreeNode*> solve(TreeNode* root) {
        if(root == NULL) {
            return {0, NULL};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        if(l.first == r.first) {
            return {l.first+1, root};
        } else if(l.first > r.first) {
            return {l.first+1, l.second};
        } else {
            return {r.first+1, r.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;   
    }
};
