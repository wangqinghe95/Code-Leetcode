/*
排序+双指针

这种方法的时间和空间复杂度很高，但是通配性比较好
可以解决 2sum,3sum,4sum...
是解决该类问题的一个模板方法
*/

class Solution {
public: 

    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumTarget(nums, 0);
    }

    vector<vector<int>> threeSumTarget(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;

        for (int i = 0; i < n; ++i)
        {
            vector<vector<int>> tuples = twoSumTarget(nums, i+1, target-nums[i]);
            for (vector<int>& tuple : tuples)
            {
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }

            while (i < n-1 && nums[i] == nums[i+1]){
                ++i;
            }
        }

        return res;
    }

    vector<vector<int>> twoSumTarget(vector<int> &nums, int start, int target)
    {
        int low = start;
        int high = nums.size() - 1;

        vector<vector<int>> res;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            int left = nums[low];
            int right= nums[high];

            if (sum < target)
            {
                while (low < high && nums[low] == left){
                    low++;
                }
            }else if (sum > target){
                while (low < high && nums[high] == right){
                    high--;
                }
            }else{
                res.push_back({left, right});
                while (low < high && nums[low] == left){
                    low++;
                }
                while (low < high && nums[high] == right){
                    high--;
                }
            }
        }

        return res;
    }
};