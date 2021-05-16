/*
dp解法
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
        {
            return 0;
        }

        int height_size = height.size();
        vector<int> left_max(height_size), right_max(height_size);

        left_max[0] = height[0];
        for (int i = 1; i < height_size; ++i)
        {
            left_max[i] = max(left_max[i-1], height[i]);
        }

        right_max[height_size-1] = height[height_size-1];
        for (int i = height_size - 2; i >= 0; --i)
        {
            right_max[i] = max(right_max[i+1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < height_size - 1; ++i)
        {
            ans += min(right_max[i], left_max[i]) - height[i];
        }

        return ans;
    }
};


/*单调栈*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int current = 0;
        stack<int> st;
        while (current < height.size())
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                {
                    break;
                }

                int distance = current - st.top() - 1;
                int boundary_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * boundary_height;
            }
            st.push(current++);
        }

        return ans;
    }
};

/*双指针*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left_max = 0, right_index = height.size() - 1;
        int right_max = 0, left_index = 0;
        while (left_index < right_index)
        {
            if (height[left_index] < height[right_index])
            {
                if (height[left_index] > left_max)
                {
                    left_max = height[left_index];
                }
                else
                {
                    ans += (left_max - height[left_index]);
                }
                left_index++;
            }
            else
            {
                if (height[right_index] > right_max)
                {
                    right_max = height[right_index];
                }
                else
                {
                    ans += (right_max - height[right_index]);
                }
                right_index--;
            }
        }

        return ans;
    }
};