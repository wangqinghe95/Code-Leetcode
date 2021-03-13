/*最大和子串*/

/*
思路还是dp
边界值：该题的边界值是使用了数组的首个元素（不知道这样理解对不对）
转移方程: f(i) = max(f(i-1)+nums[i],nums[i])

换句话说，就是 sum 的值是否大于 0，大于0，就可以加上当前的nums[i]（和就相当于增加了）
否则，直接把nums[i]给sum
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int len = nums.size();
        if (len == 1){
            return nums[0];
        }
        int dp[len+1];
        memset(dp, 0, sizeof(dp));

        dp[0] = nums[0];
        for(int i = 1; i < len; ++i){
            if (dp[i-1] + nums[i] >= nums[i]){
                dp[i] = dp[i-1] + nums[i];
            }
            else{
                dp[i] = nums[i];
            }
        }

        int max_nums = dp[0];
        for(int i = 1; i < len; ++i){
            if (dp[i] > max_nums){
                max_nums = dp[i];
            }
        }

        return max_nums;
    }
};