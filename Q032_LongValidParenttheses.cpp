/*
use stack to simulate parentheses in and out
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_ans = 0;
        stack<int> stk;
        stk.push(-1);

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    max_ans = max(max_ans, i - stk.top());
                }
            }
        }

        return max_ans;
    }
};

/*

*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int max_value = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }

            if (left == right)
            {
                max_value = max(max_value, 2 * right);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }

            if (left == right)
            {
                max_value = max(max_value, 2 * right);
            }
            else if (right < left)
            {
                left = right = 0;
            }
        }

        return max_value;

    }
};

/*
动态规划
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_value = 0;

        int size = s.size();
        vector<int> dp(size, 0);

        for (int i = 1; i < size; ++i)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = 2;
                    if (i - 2 >= 0)
                    {
                        dp[i] += dp[i - 2];
                    }
                }
                else if (dp[i - 1] > 0)
                {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 >= 0)
                        {
                            dp[i] += dp[i - dp[i - 1] - 2];
                        }
                    }
                }			
            }
            max_value = max(max_value, dp[i]);
        }
        return max_value;

    }
};
