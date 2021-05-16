/*
字符串匹配
p[j] == s[i] : dp[i][j] = dp[i-1][j-1]
p[i][j] == '.' dp[i][j] = dp[i-1][j-1]
p[i][j] == '*' 
    1) p[j-1] != s[i] dp[i][j] = dp[i][j-2]
    2) p[j-1] == s[i] dp[i][j] = dp[i-1][j] || dp[i][j] = dp[i][j-1] || dp[i][j] = dp[i][j-2]

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if (s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*'){
                    if (s[i-1] != p[j-2] && p[j-2] != '.'){
                        dp[i][j] = dp[i][j-2];
                    }
                    else{
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};