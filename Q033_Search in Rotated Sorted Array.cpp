
/*暴力遍历*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        for (int num : nums){
            if (num == target){
                return i;
            }
            i++;
        }
        return -1;
    }
};

/*二分查找-变形*/
/*
旋转有序数组对于有序数组的区别在于部分区域有序
所以如果要使用二分法就需要对其有额外的步骤来排除掉部分有序这个限制条件
对于数组[4,5,6,7,0,1,2]
nums[mid] = 7 , nums[0] < nums[mid] 说明在有序区间
                        如果 (nums[0] < target && target < nums[mid])(target = 5)
                        就相当于转化成有序数组中找目标 直接把 r = mid-1
                        否则，target在另一侧， l = mid+1（target = 1）

总体的思路就是，0~mid 和 mid-n 这两个区域中先找有序的区域，不断地在有序的区域中
根据target值缩减 left 和 right 的边界
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
    if (nums.size() < 1){
        return -1;
    }
    if (nums.size() == 1){
        return nums[0] == target ? 0 : -1;
    }

    int l = 0;
    int r = nums.size() - 1;
    while(l <= r){
        int mid = (l+r) / 2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[0] <= nums[mid]){
            if (nums[mid] > target && nums[0] <= target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            if (nums[mid] < target && target <= nums[nums.size() - 1]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    return -1;
    }
};


/*
该方法是找到的区域不是target所在区域，比target小就置为最小值(MIN)，比target就置为最大值(MAX)
这样强制构造成有序数组，可以直接使用二分查找
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int MAX = 100000000;
        const int MIN = -1000000000;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target){
                return mid;
            }

            if (target >= nums[0]){
                if (nums[mid] < nums[0]){
                    nums[mid] = MAX;
                }
            }
            else{
                if (nums[mid] >= nums[0]){
                    nums[mid] = MIN;
                }
            }

            if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};
