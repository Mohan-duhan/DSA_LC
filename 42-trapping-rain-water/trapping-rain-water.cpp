class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int leftMax = arr[left];
        int rightMax = arr[right];
        int waterTrapped = 0;

        while (left <= right) {
            // case 1 : if left boundary is smaller
            if (leftMax < rightMax) {
                leftMax = max(leftMax, arr[left]);
                waterTrapped += leftMax - arr[left];
                left++;
            }
            // case 2 : if rightboundary is smaller
            else {
                rightMax = max(rightMax, arr[right]);
                waterTrapped += rightMax - arr[right];
                right--;
            }
        }
        return waterTrapped;
    }
};