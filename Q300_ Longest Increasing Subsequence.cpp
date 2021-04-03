/*
最长递增子序列
动态规划

初始状态：dp[0] = nums[0]
动态转移方程：LIS(length) = max(dp[i]),其中 0 <= i < n
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        vector<int> dp(nums.size()+1);

        dp[0] = 1;
        int maxAns = 1;
        for (int i = 0; i < nums.size(); ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if (nums[i] > nums[j]){
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                }
            }
            maxAns = maxAns > dp[i] ? maxAns : dp[i];
        }
        return maxAns;
    }
};