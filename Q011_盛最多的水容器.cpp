/*
双指针
*/



int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize - 1;
    int max = -1;

    int temp_index;
    int temp_area;
    while (i < j)
    {
        temp_index = height[i] > height[j] ? j : i;
        temp_area = height[temp_index] * (j - i);

        if (temp_index == i)
        {
            ++i;
        }
        else
        {
            --j;
        }

        if (max  < temp_area)
        {
            max = temp_area;
        }
    }

    return max;
}

