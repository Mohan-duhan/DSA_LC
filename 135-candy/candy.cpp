class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        //left se right
        // Agar current child ka rating apne left wale se zyada hai
        // to usko left wale se zyada candies deni hain
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        //right se left
        // Agar current child ka rating apne right wale se zyada hai
        // to usko right wale se zyada candies deni hain
        // max use kiya kyunki pehle pass me already kuch candies assign ho chuki hain
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sabhi candies ko add karke minimum total candies nikalte hain
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
