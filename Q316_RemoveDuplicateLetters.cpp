/*
去除重复元素并且要求不改变字符串顺序的最小字典序排序
思路：
先计算出每个元素的个数
在从头遍历字符串，
如果没有被访问过：
    1：循环栈，判断栈不空且栈顶字符字典序大于当前遍历的字符，
        1：该字符个数大于0，就把该元素置为未访问过，且弹出栈
        2：退出循环栈
    置该字符为访问过，且压栈
字符数量减1
如果访问过，就
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
	vector<int> num(26), vis(26);

	for (char ch : s)
	{
		num[ch - 'a']++;
	}

	string stk;
	for (char ch : s)
	{
		if (!vis[ch - 'a'])
		{
			while (!stk.empty() && stk.back() > ch)
			{
				if (num[stk.back() - 'a'] > 0)
				{
					vis[stk.back() - 'a'] = 0;
					stk.pop_back();
				}
                else
                {
                    break;
                }
			}
			vis[ch - 'a'] = 1;
			stk.push_back(ch);
		}
		num[ch - 'a'] -= 1;
	}

	return stk;
    }
};