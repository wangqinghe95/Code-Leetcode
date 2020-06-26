hash数组法：

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE  2048

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int hash[MAX_SIZE];
    int* res = (int*)malloc(2 * sizeof(int));
    memset(hash, -1, sizeof(hash));
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE] != -1)
        {
            res[0] = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;  //防止负数下标越界，循环散列
    }

    return NULL;
}

这种方法是对于hash初始化为-1，但是memset会影响性能，所以可以使用将所有下标序号都给往前移动一位

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE  2048

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int hash[MAX_SIZE] = {0};
    int* return_array = (int*)malloc(2 * sizeof(int));
    int i;
    for ( i = 0; i < numsSize; ++i)
    {
        if (hash[(target - nums[i] + 1 + MAX_SIZE) % MAX_SIZE] != 0)
        {
            return_array[0] = hash[(target - nums[i] + 1 + MAX_SIZE) % MAX_SIZE] - 1;
            return_array[1] = i;
            *returnSize = 2;
            return return_array;
        }

        hash[(1 + nums[i] + MAX_SIZE) % MAX_SIZE] = i + 1;
    }

    return NULL;
}

解题思路来自本题的题解