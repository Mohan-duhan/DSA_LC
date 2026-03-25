class Solution { 
public: 
    bool canPartitionGrid(vector<vector<int>>& grid) { 
        int m = grid.size(); 
        int n = grid[0].size(); 

        long long  totalSum = 0; 
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < n; j++) { 
                totalSum += grid[i][j]; 
            } 
        } 
        long long  rowSum = 0;
        for (int i = 0; i < m - 1; i++) { 
            for (int j = 0; j < n; j++) { 
                rowSum += grid[i][j]; 
            } 
            if (2 * rowSum == totalSum) { 
                return true; 
            } 
        } 

        long long  colSum = 0;
        for (int j = 0; j < n - 1; j++) { 
            for (int i = 0; i < m; i++) { 
                colSum += grid[i][j]; 
            } 
            if (2 * colSum == totalSum) { 
                return true; 
            } 
        } 

        return false; 
    } 
};