/*
时间复杂度：100%
*/

class Solution {
public:
    int reverse(int x) {
        long lRet = 0;
        while (0 != x)
        {
            lRet = lRet * 10 + x % 10;
            x /= 10;
        }

        if ((int)lRet != lRet)
        {
            return 0;
        }

        return (int)lRet;
    }
};

/*

*/