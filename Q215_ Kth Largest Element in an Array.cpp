//栈溢出
//栈溢出的原因是 如果传进来的nums的元素个数小于2，为1时，会出现这个问题
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = (n - 2) / 2; i >= 0; --i)
        {
            //percdown(nums, n, i);
            updown(nums, n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            int temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
            //percdown(nums, i, 0);
            updown(nums, i, 0);
        }
        return nums[k];
    }

    void updown(vector<int>& nums, int n, int i)
    {
        int x = nums[i];
        int child;
        for (; i * 2 + 2 <= n; i = child) {
            child = i * 2 + 1;
            if (child < n - 1 && nums[child] < nums[child + 1]) {
                child++;
            }
            if (x > nums[child]) {
                nums[i] = nums[child];
            }
            else {
                break;
            }
        }
        nums[i] = x;
    }
};

//修改后


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)  //nums = {1}, k = 1情况
        {
            return nums[k-1];
        }
        for (int i = (n - 2) / 2; i >= 0; --i)
        {
            percdown(nums, n, i);
            //updown(nums, n, i);
        }

        for (int i = n - 1; i >= n-k+1; i--)    //只排序 n-k+1次， 然后直接返回 堆顶元素，就是第K大的
        {
            int temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
            percdown(nums, i, 0);
            //updown(nums, i, 0);
        }
        return nums[0]; 
    }

    void updown(vector<int>& nums, int n, int i)
    {
        int x = nums[i];
        int child;
        for (; i * 2 + 2 <= n; i = child) {
            child = i * 2 + 1;
            if (child < n - 1 && nums[child] < nums[child + 1]) {
                child++;
            }
            if (x > nums[child]) {
                nums[i] = nums[child];
            }
            else {
                break;
            }
        }
        nums[i] = x;
    }

    void percdown(vector<int>& nums, int n, int i)
    {
        int x = nums[i];
        int child;
        for (; i * 2 + 2 <= n; i = child) {
            child = i * 2 + 1;
            if (child < n-1 && nums[child] < nums[child + 1]) {
                child++;
            }
            if (x < nums[child]) {
                nums[i] = nums[child];
            }
            else {
                break;
            }
        }
        nums[i] = x;
    }
};


//快排
class Solution {
public:

    int quickSort(vector<int>& nums, int low, int high, int index) {
        if (low < high) {
            int pivotpos = partiotion(nums, low, high);
            if (pivotpos == index) {
                return nums[pivotpos];
            }
            else if (pivotpos > index) {
                return quickSort(nums, 0, pivotpos - 1, index);
            }
            else {
                return quickSort(nums, pivotpos + 1, high, index);
            }
        }
        else{
            return nums[index];
        }
    }

    int partiotion(vector<int>& nums, int low, int high) {
        int tmp = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= tmp) {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= tmp) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = tmp;
        return low;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

