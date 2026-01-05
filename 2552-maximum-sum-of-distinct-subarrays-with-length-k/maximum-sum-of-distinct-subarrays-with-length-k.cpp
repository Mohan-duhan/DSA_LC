class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long currSum = 0;
        long long maxSum = 0;
        int i = 0;

        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;//maintain freq
            currSum += nums[j];//generate sum

            while (mp[nums[j]] > 1) {//if frequency of any on eelement increases start shrinking the window
                mp[nums[i]]--;//firstly remove that ele
                currSum -= nums[i];//then subs that val from sum 
                i++;//move starting pointer ahead
            }

            if (j - i + 1 > k) {
                mp[nums[i]]--;
                currSum -= nums[i];
                i++;
            }

            if (j - i + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};