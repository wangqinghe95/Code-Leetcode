/*
multiply two string by simulating addition 
*/
string addString(string &num1, string& num2)
{
    int m = num1.size() - 1;
    int n = num2.size() - 1;
    int add = 0;
    string ans;
    while (m >= 0 || n >= 0 || add != 0)
    {
        int x = m >= 0 ? num1.at(m) - '0' : 0;
        int y = n >= 0 ? num2.at(n) - '0' : 0;

        int result = x + y + add;
        ans.push_back(result % 10);
        add = result / 10;
        --m;
        --n;
    }

    reverse(ans.begin(), ans.end());
    for (auto &c : ans)
    {
        c += '0';
    }

    return ans;
}

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }

    string ans = "0";
    for (int i = num2.size() - 1; i >= 0; --i)
    {
        int add = 0;
        string cur;
        for (int j = num2.size() - 1; j > i; --j)
        {
            cur.push_back(0);
        }

        int y = num2.at(i) - '0';
        for (int j = num1.size() - 1; j >= 0; --j)
        {
            int x = num1.at(j) - '0';
            int product = x * y + add;
            cur.push_back(product % 10);
            add = product / 10;
        }

        while ( add != 0)
        {
            cur.push_back(add % 10);
            add /= 10;
        }

        reverse(cur.begin(), cur.end());

        for (auto &c : cur)
        {
            c += '0';
        }

        ans = addString(ans, cur);
    }
    return ans;
}


/*
multiply two string by simulating multiply 
*/

/*
multiply two string by simulating multiply -- optimized version  
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        
        vector<int> res(num1.size() + num2.size());
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int n1 = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int n2 = num2[j] - '0';
                int sum = (res[i + j + 1] + n1 * n2);
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string ans;
        for (int i = 0; i < res.size(); i++)
        {
            if (0 == i && 0 == res[i])
            {
                continue;
            }
            ans.push_back(res[i] + '0');
        }

        return ans;
    }
};