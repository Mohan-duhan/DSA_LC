class Solution {
public:
    vector<int> left;
    vector<int> right;
    int n;

    void leftSmaller(vector<int>& heights) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void rightSmaller(vector<int>& heights) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        left.resize(n);
        right.resize(n);

        leftSmaller(heights);
        rightSmaller(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
