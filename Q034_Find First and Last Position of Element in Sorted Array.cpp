/*在一个有序数组中搜索目标元素的第一个和最后一个下标*/

/* 
思路1：
直接使用二分法找到目标元素下标，
然后再从该下标前后找到不是该元素的下标（注意边界）
*/

class Solution {
public:
    int searchIndex(vector<int>&nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (nums[ mid ] == target) {
                return mid;
            }
            else if (nums[ mid ] > target) {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans { -1,-1 };
        int index = searchIndex(nums, target);
        if (index != -1){
            int min = index, max = index;
            for (int i = index; i >= 0 && nums[i] == target; i--){
                min = i;
            }
            for (int j = index; j < nums.size() && nums[j] == target; j++){
                max = j;
            }
            ans[ 0 ] = min;
            ans[ 1 ] = max;
        }
        return ans;
    }
};

/*
二分法-变形
在有序数组中查找可能是重复元素的范围
二分法中左边界 可以使用 nums[mid] >= target index = mid 来确认
右边界使用 nums[mid] > target , index = mid - 1 来确认

最后要判断左边界和右边界的合法性
*/

class Solution {
public:
    int searchIndex(vector<int> &nums, int target, bool isLeft){
        int left = 0;
        int right = nums.size() - 1;
        int ans =  nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[ mid ] > target || (isLeft && nums[ mid] >= target)){
                right = mid - 1;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        int leftIndex = searchIndex(nums, target, true);
        int rightIndex = searchIndex(nums, target, false) - 1;
        if (leftIndex <= rightIndex && rightIndex <= nums.size() 
            && nums[leftIndex] == target && nums[rightIndex] == target){
            return vector<int> {leftIndex, rightIndex};
        }
        return vector<int>{-1, -1};
    }
};