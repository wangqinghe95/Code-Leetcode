/*哈希检测循环*/

class Solution {

private:
    int getNext(int n)
    {
        int totalSum = 0;
        while ( n > 0)
        {
            int d = n % 10;
            n /= 10;
            totalSum += d * d;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        set<int> seen;
        while (1 != n && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

/*快慢指针*/

class Solution {

private:
    int getNext(int n)
    {
        int totalSum = 0;
        while ( n > 0)
        {
            int d = n % 10;
            n /= 10;
            totalSum += d * d;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);

        while (fastRunner != 1 && slowRunner != fastRunner)
        {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        
        return fastRunner == 1;
    }
};