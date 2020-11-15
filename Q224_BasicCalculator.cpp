
/*
有限自动状态机、逆波兰表达式

前提约束：
加号、减号、左括号、右括号、非负整数、空格
-3-(5+2)    这种不在测试用例范围
*/

class Solution {
public:
    void compute(stack<int>& number, stack<char>& operation)
    {
        if (number.size() < 2)
        {
            return;
        }
        int num2 = number.top();
        number.pop();
        int num1 = number.top();
        number.pop();
        if (operation.top() == '+')
        {
            number.push(num1 + num2);
        }
        else if (operation.top() == '-')
        {
            number.push(num1 - num2);
        }
        operation.pop();
    }
    int calculate(string s) {
        const int STATE_BEGIN = 0;
        const int STATE_NUMBER = 1;
        const int STATE_OPERATION = 2;

        stack<int> stk_number;
        stack<char> stk_operation;
        int number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ') continue;
            switch (STATE)
            {
            case STATE_BEGIN:
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = STATE_NUMBER;
                }
                else
                {
                    STATE = STATE_OPERATION;
                }
                i--;
                continue;
            }
            case STATE_NUMBER:
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    number = number * 10 + (s[i] - '0');
                }
                else
                {
                    stk_number.push(number);
                    if (compuate_flag == 1)
                    {
                        compute(stk_number, stk_operation);
                    }
                    number = 0;
                    i--;
                    STATE = STATE_OPERATION;
                }
                continue;
            }
            case STATE_OPERATION:
            {
                if (s[i] == '+' || s[i] == '-')
                {
                    stk_operation.push(s[i]);
                    compuate_flag = 1;
                }
                else if (s[i] == '(')
                {
                    STATE = STATE_NUMBER;
                    compuate_flag = 0;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = STATE_NUMBER;
                    i--;
                }
                else if (s[i] == ')')
                {
                    compute(stk_number, stk_operation);
                }
                continue;
            }
            default:
                break;
            }
        }

        if (number != 0)
        {
            stk_number.push(number);
            compute(stk_number, stk_operation);
        }
        if (number == 0 && stk_number.empty())
        {
            return 0;
        }
        return stk_number.top();
    }  
};

/*
stack
*/

class Solution {
public:

    int calculate(string s) {
         stack<int> sign;
        sign.push(1);
        int ans = 0, num = 0, op = 1;
        for (char c : s)
        {
            if (c == ' ')
            {
                continue;
            }
            if (c >= '0' && c <= '9')
            {
                num = num * 10 + (c - '0');
                continue;
            }

            ans += op * num;
            num = 0;
            if (c == '+')
            {
                op = sign.top();
            }
            else if (c == '-')
            {
                op = -sign.top();
            }
            else if (c == '(')
            {
                sign.push(op);
            }
            else if (c == ')')
            {
                sign.pop();
            }
        }

        ans += op * num;
        return ans;
    }
};