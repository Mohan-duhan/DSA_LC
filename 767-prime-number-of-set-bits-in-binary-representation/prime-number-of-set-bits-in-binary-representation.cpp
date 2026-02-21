class Solution {
public:
    bool checkPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int setBits = 0;
        int cnt = 0;

        for (int i = left; i <= right; i++) {
            setBits = __builtin_popcount(i);
            if (checkPrime(setBits)) {
                cnt++;
            }
        }
        return cnt;
    }
};