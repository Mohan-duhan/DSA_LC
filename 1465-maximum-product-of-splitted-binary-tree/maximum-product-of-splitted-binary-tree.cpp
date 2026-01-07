class Solution {
public:
    const int mod=1e9+7;
    long long ans=INT_MIN, total=0;
    int dfs(TreeNode* root){
        if (!root) return 0;
        int sum=root->val+dfs(root->left)+dfs(root->right);
        ans=max(ans, (total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total=dfs(root);
        dfs(root);
        return ans%mod;
    }
};