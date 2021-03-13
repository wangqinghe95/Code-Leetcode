/*最长回文子序列*/

/*
dp 思路：
dp 思路最主要是找边界和转移方程
边界：字串的长度为1或者长度为2并且两个字母相同
转移方程：P(i,j) = P(i+1, j-1) && S[i] == S[j]
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int dp[len+1][len+1];
        memset(dp,0,sizeof(dp));

        int start_index = 0;
        int ans_length = 1;
        for (int i = 0; i < len; ++i){
            dp[i][i] = 1;
            if (i < len - 1){
                if (s[i] == s[i+1]){
                    dp[i][i+1] = 1;
                    ans_length = 2;
                    start_index = i;
                }
            }
        }

        for (int L = 3; L <= len; L++){
            for(int i = 0; i + L - 1 < len; ++i){
                int j = i + L - 1;
                if (s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    if(ans_length < L){
                        start_index = i;
                        ans_length = L;
                    }
                    
                }
            }
        }

        string ans;
        for(int i = 0; i < ans_length; i++){
            ans.push_back(s[i+start_index]);
        }

        return ans;
    }
};