class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // accumulate is a stl method used to find the sum of any vector all
        // elements.
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalCost > totalGas) // it will never be possible if the kharch is
                                  // more then kamai
            return -1;

        int idx = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (total < 0) { // move forward if gas[i] < cost[i] , that means
                             // total will be negative
                idx = i + 1;
                total = 0;
            }
        }
        return idx;
    }
};
