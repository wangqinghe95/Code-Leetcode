/*
括号匹配

*/

//方法1 暴力遍历所有可能

class Solution {
    bool isValid(const string &s){
        int balance = 0;
        for(char c : s){
            if (c == '('){
                ++balance;
            }
            else{
                --balance;
            }

            if (balance < 0){
                return false;
            }
        }
        return balance == 0;
    }
    void generate_all(string &current, int n, vector<string>& result){
        if (n == current.size()){
            if (isValid(current)){
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n *2, result);
        return result;
    }
};

//方法2 回溯法
//如果左括号的数量不大于n，添加一个左括号，如果右括号的数量小于左括号的数量，我们可以放一个右括号

class Solution {
public:
    void backtrace(vector<string> &result, string& cur, int open, int close, int n){
        if (cur.size() == n * 2){
            result.push_back(cur);
            return;
        }

        if (open < n){
            cur.push_back('(');
            backtrace(result, cur, open+1, close, n);
            cur.pop_back();
        }

        if (close < open){
            cur.push_back(')');
            backtrace(result, cur, open, close+1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrace(result, current, 0, 0, n);
        return result;
    }
};

//方法3 按括号长度递归

class Solution {
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    shared_ptr<vector<string>> generate(int n){
        if (cache[n] != nullptr){
            return cache[n];
        }

        if (0 == n){
            cache[0] = shared_ptr<vector<string>> (new vector<string>{""});
        }
        else{
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i){
                auto lefts = generate(i);
                auto rights = generate(n-i-1);
                for (const string& left : *lefts){
                    for( const string& right : *rights){
                        result->push_back("(" + left + ")" + right);
                    }
                }
            }
            cache[n] = result;
        }
        return cache[n];
    }
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};

