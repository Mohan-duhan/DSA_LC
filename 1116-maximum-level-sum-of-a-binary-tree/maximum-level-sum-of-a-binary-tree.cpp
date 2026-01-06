class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* root, int level) {
        if (root == NULL) return;

        if (level == res.size()) {
            res.push_back({});
        }

        res[level].push_back(root->val);

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;

        dfs(root, 0);

        int maxSum = INT_MIN;
        int minLevel = 1;

        for (int i = 0; i < res.size(); i++) {
            int sum = 0;
            for (int j = 0; j < res[i].size(); j++) {
                sum += res[i][j];
            }

            if (sum > maxSum) {
                maxSum = sum;
                minLevel = i + 1; // 1-based indexing
            }
        }

        return minLevel;
    }
};
