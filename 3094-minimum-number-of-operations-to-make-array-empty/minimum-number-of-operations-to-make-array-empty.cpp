class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;

        for (int num : nums) {
            mp[num]++;
        }

        for (auto& it : mp) {
            if (it.second == 1)
                return -1;
            else if (it.second % 3 == 0) {
                cnt += it.second / 3;
            } else {
                cnt += it.second / 3 + 1;
            }
        }
        return cnt;
    }
};