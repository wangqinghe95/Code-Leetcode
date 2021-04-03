/*
最长相同字串

不要求连续，只要求字符的相对顺序一致即可

动态转移方程：
边界情况： 当i = 0,0 <= j <= m 时, dp[0][j] = 0 ; 当 j = 0 ,0 <= i <= n 时, dp[0][j] = 0 
动态转移方程：dp[i][j] = dp[i-1][j-1], text1[i-1] == text2[j]
             dp[i][j] = max(dp[i-1][j],dp[i][j-1])
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int i = 1; i <= text1.size(); ++i){
            for (int j = 1; j <= text2.size(); ++j){
                if (text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

