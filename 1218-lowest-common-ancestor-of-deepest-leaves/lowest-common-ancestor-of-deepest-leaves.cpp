class Solution {
public:
    unordered_map<TreeNode*, int> depthMap;
    int maxD = 0;

    void depth(TreeNode* root, int d) {
        if (!root) return;
        depthMap[root] = d;
        maxD = max(maxD, d);
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }

    TreeNode* solve(TreeNode* root) {
        if (!root) return nullptr;

        // If this node is one of the deepest leaves
        if (depthMap[root] == maxD) return root;

        TreeNode* l = solve(root->left);
        TreeNode* r = solve(root->right);

        if (l && r) return root;
        return l ? l : r;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return solve(root);
    }
};
