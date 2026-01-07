class Solution {
public:
    const int MOD = 1e9 + 7;
    long long ans = 0;
    long long total = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + dfs(root->left) + dfs(root->right);
    }

    int solve(TreeNode* root) {
        if (root == nullptr) return 0;

        int currSum = root->val + solve(root->left) + solve(root->right);
        ans = max(ans, 1LL * currSum * (total - currSum));
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        total = dfs(root);
        solve(root);
        return ans % MOD;
    }
};
