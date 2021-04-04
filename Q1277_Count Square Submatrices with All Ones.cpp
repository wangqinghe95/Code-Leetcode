/*
在一个 m*n 方块中，统计边长为1的正方形的数量

动态规划：
初始状态：i = 0, 0 <= j < n; dp[i][j] = 0;
         j = 0, 0 <= i < m; dp[i][j] = 0;

动态转移方程：dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (0 == i || 0 == j){
                    dp[i][j] = matrix[i][j];
                }
                else if (0 == matrix[i][j]){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+1;
                }
                 ans += dp[i][j];
            }           
        }
        return ans;
    }
};