/*
使用辅助栈判定
*/

class Solution {
public:
    bool isValid(string s) {
    if (s.size() % 2 != 0)
    {
        return false;
    }

    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        switch (c)
        {
        case '[':
            st.push(']');
            break;
        case '(':
            st.push(')');
            break;
        case '{':
            st.push('}');
            break;
        default:
            if (st.empty() || c != st.top())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    return st.empty();
    }
};