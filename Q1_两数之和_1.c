/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *return_array = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize - 1; ++i)
    {   
        for (int j = numsSize - 1 ; j > i; --j)
        {
            if (nums[i] + nums[j] == target)
            {
                return_array[0] = i;
                return_array[1] = j;
                *returnSize = 2;
                return return_array;
            }
        }
    }

    return NULL;
}