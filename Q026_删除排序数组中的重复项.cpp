/*
C
*/

int removeDuplicates(int* nums, int numsSize){
    int removeNums = 0;
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i-1])
        {
            removeNums++;
        }
        else
        {
            nums[i-removeNums] = nums[i];
        }
    }
    return numsSize-removeNums;
}

/*
C++
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            # if 1
            if (nums[i] == nums[j])
            {
                ++j;
            }
            else
            {
                ++i;
                nums[i] = nums[j];
                ++j;
            }
            #else
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
            ++j;
            #endif
        }
        return i+1;
    }
};

/*使用STL*/

//unique 函数会去掉排序容器中的重复元素，并返回尾地址，所以再减掉首地址就得到长度了。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
};