class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int curX = points[i][0];
            int curY = points[i][1];

            int tarX = points[i + 1][0];
            int tarY = points[i + 1][1];

            ans += max(abs(tarX - curX), abs(tarY - curY));
        }
        return ans;
    }
};