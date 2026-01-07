class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;

        bool isNegative = num < 0;
        num = llabs(num);

        string s = to_string(num);

        if (isNegative) {
            // For negative number: sort digits in descending order
            sort(s.begin(), s.end(), greater<char>());
        } else {
            // For positive number: sort digits in ascending order
            sort(s.begin(), s.end());

            // Move first non-zero digit to the front to avoid leading zeros
            if (s[0] == '0') {
                for (int i = 1; i < s.size(); i++) {
                    if (s[i] != '0') {
                        swap(s[0], s[i]);
                        break;
                    }
                }
            }
        }

        long long ans = stoll(s);
        return isNegative ? -ans : ans;
    }
};
