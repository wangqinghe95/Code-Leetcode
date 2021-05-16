/*
按照字符串转数字的正常思路
*/

class Solution {
public:
    int myAtoi(string s) {
        long ret = 0;
        int flag = 1;  //default the number is positive 
        int i = 0; 
        for ( ; s[i] == ' '; ++i);

        switch (s[i])
        {
            case '-': flag = -1;
            case '+': ++i;
        }

        if (s[i] > '9' || s[i] < '0')
        {
            return 0;
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            ret = ret * 10 + (s[i] - '0');
            if ((int)ret != ret)
            {
                return (flag == 1 ) ? (INT_MAX) : (INT_MIN);
            }
            i++;
        }

        ret *= flag;
        return (int)ret;
    }
};

/*
有限状态机
*/

class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c)
    {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

    public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c -'0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string s) {
        Automaton automaton;
        for (char c : s)
        {
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};