/*
动态规划
边界添加：dp[1] = 1, dp[2] = 1（一次上一个或两个台阶）
转移公式：dp[i] = dp[i-1] + dp[i-2] (i >= 2)
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[ 0 ] = 1;
        dp[ 1 ] = 1;
        for (int i = 2; i < n+1; ++i){
            dp[ i ] = dp[ i-1 ] + dp[ i - 2 ];
        }

        return dp[ n ];
    }
};

/*
递归：
暴力递归肯定会超时
所以这里是使用带记忆数组的递归

*/

class Solution {
public:
    int climb(int n, vector<int> &mem){
        if (n==0 || n==1){
            return 1;
        }
        if (mem[n] == -1){
            mem[ n ] = climb(n-1, mem) + climb(n-2, mem);
        }
        return mem[ n ];
    }
    int climbStairs(int n) {
        vector<int> mem(n + 1, -1);        
        return climb(n, mem);
    }
};