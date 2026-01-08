class Solution {
public:
    const int NEG_INF = -1000000000;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i >= nums1.size() || j >= nums2.size()) {
            return NEG_INF;
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int prod = nums1[i] * nums2[j];

        int option1 = prod;
        int option2 = prod + solve(i + 1, j + 1, nums1, nums2);
        int option3 = solve(i + 1, j, nums1, nums2);
        int option4 = solve(i, j + 1, nums1, nums2);

        return dp[i][j] = max({option1, option2, option3, option4});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size(), vector<int>(nums2.size(), INT_MIN));
        return solve(0, 0, nums1, nums2);
    }
};
