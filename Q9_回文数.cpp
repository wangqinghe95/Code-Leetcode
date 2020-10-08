/*
使用了C的库函数和C++string的内置函数
在C++中使用C的语法，那速度真的是杠杠的
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        //string tmp = to_string(x);
        char tmp[100] = {};
        sprintf(tmp, "%d", x);
        //int length = tmp.size();
        int length = strlen(tmp);
        for (int i = 0; i < length; ++i)
        {
            if (tmp[i] != tmp[length - i - 1])
            {
                return false;
            }
        }
        return true;

    }
};