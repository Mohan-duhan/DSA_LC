class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        // if the count of -ve numbers is odd then one ele remains -ve anyhow
        // and of its even then convert each ele +ve and add them
        int n = mat.size();
        long long sum = 0;
        int cnt = 0;
        int minEle = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] < 0)
                    cnt++;
                minEle = min(minEle, abs(mat[i][j]));
                sum += abs(mat[i][j]);
            }
        }
        if (cnt % 2 == 0) {
            return sum;
        } else {
            return (long long)(sum - 2*minEle);
        }
    }
};