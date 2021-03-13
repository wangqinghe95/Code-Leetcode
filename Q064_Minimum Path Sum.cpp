/*
求最小和路径
dp数组：
边界(i表示行，j表示列)：
i == 0 && j == 0：dp[0][0] = grid[0][0]
i >= 1 && j == 0：dp[i][0] = grid[i][0] + dp[i-1][0]
i >= 1 && j == 0：dp[0][j] = grid[j][0] + dp[j-1][0]
i >= 1 && j >= 1: dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j]

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int rows = grid.size();
        int columns = grid[0].size();
        auto dp = vector< vector<int> >(rows, vector<int> (columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < columns; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[rows - 1][columns - 1];
    }
};