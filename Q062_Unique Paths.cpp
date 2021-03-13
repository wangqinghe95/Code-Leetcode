/*
求路径数

思路是dp数组：
边界值：dp[0][i] 和 dp[j][0] 都为 1。本身自己到自己的格数为1
转移方程：f(i,j) = f(i-1,j) + f(i,j-1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};