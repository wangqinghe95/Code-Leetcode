/*
暴力法-除模
*/

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10)
        {
            num = num / 10 + num % 10;
        }
        return num;
    }
};

/*
数学分析：O（1）
*/

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};