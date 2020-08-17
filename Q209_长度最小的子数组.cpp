/*双指针+二分法*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (0 == n)
        {
            return 0;
        }

        vector<int> sums(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int ans = 1e7;
        for (int i = 1; i <= n; ++i)
        {
            int target = s + sums[i - 1];
            auto bounder = lower_bound(sums.begin(), sums.end(), target);
            if (bounder != sums.end())
            {
                int temp = static_cast<int>(bounder - sums.begin());
                ans = min(ans, temp - (i - 1));
            }
        }

        return ans == 1e7 ? 0 : ans;
    }
};


/*双指针*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if ( 0 == n )
        {
            return 0;
        }

        int ans = 1e7;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min( ans, (end - start + 1 ) );
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return ans == 1e7 ? 0 : ans;
    }
};