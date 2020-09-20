/*笨办法*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() < 3)
        {
            return s;
        }
        vector<vector<char>> str(numRows);
        int col = numRows > s.length() ? numRows : s.length();
        for (int i = 0; i < numRows; ++i)
        {
            str[i].resize(col);
        }

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                str[i][j] = ' ';
            }
        }

        int i = 0, j = 0, k = 0;
        while (i < numRows && j < col && k < s.length())
        {
            while (i < numRows && k < s.length())
            {
                str[i++][j] = s[k++];
            }
            if (i > 1)
            {
                i--;
            }
            i--, j++;
            while (j < col && i > 0 && k < s.length())
            {
                str[i--][j++] = s[k++];
            }
            
        }
        
        string sTmp;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (str[i][j] != ' ')
                {
                    sTmp.push_back(str[i][j]);
                }
            }
        }
        return sTmp;
    }
};

/*官方题解*/

class Solution {
public:
    string convert(string s, int numRows) {
	if (numRows == 1)
	{
		return s;
	}
	vector<string> rows(min(numRows, int(s.size())));
	int cur_Row = 0;
	bool goingDown = false;

	for (char c : s)
	{
		rows[cur_Row] += c;
		if (cur_Row == 0 || cur_Row == numRows - 1)
		{
			goingDown = !goingDown;
		}
		cur_Row += goingDown ? 1 : -1;
	}

	string ret;
	for (string row : rows)
	{
		ret += row;
	}
	return ret;
    }
};