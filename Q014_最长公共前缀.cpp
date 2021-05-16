/*
纵向扫描法：
从前往后遍历所有字符串的每一列
比较相同列上的字符是否相同
如果相同则继续下一列比较
如果不相同则当前列不再属于公共前缀，当前列之前的部分为最长公共前缀
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
        {
            return "";
        }

        string strCom = "";
        string strFir = strs[0];
        for (int i = 0; i < strFir.size(); ++i)
        {
            bool isCharCom = true;
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strFir[i] != strs[j][i])
                {
                    isCharCom = false;
                    break;
                }
            }
            if (isCharCom)
            {
                strCom += strFir[i];
            }
            else
            {
                break;
            }
        }
        return strCom;
    }
};


/**
 横向比较法：
 依次遍历字符串数组中的每个字符串
 对于每个遍历到的字符串，更新最长公共前缀
 当遍历完所有的字符串后，即可得到字符串数组的最长公共前缀
 如果尚未 遍历完所有的字符串时，最长公共前缀已经是空串时
 那么最长公共前缀就一定是空串，因此不需要继续遍历剩下的字符串
 直接返回空串即可
 */
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
        {
            return "";
        }

        string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i)
        {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size())
            {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(string &str1, string &str2)
    {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index])
        {
            ++index;
        }
        return str1.substr(0, index);
    }
};

/*
分治法
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
        {
            return "";
        }
        else
        {
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }
    
    string longestCommonPrefix(const vector<string>& strs, int start, int end)
    {
        if (start == end)
        {
            return strs[start];
        }
        else
        {
            int mid = (start + end) / 2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid+1, end);
            return commonPrefix(lcpLeft, lcpRight); 
        }
    }

    string commonPrefix(const string &str1, const string &str2)
    {
        int minLength = min(str1.size(), str2.size());
        for (int i = 0; i < minLength; ++i)
        {
            if (str1[i] != str2[i])
            {
                return str1.substr(0, i);
            }
        }
        
        return str1.substr(0, minLength);
    }
};

/*
二分查找
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
        {
            return "";
        }

        int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t){return s.size() < t.size();})->size();

        int low = 0, high = minLength;
        while (low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if (isCommonPrefix(strs, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, low);
    }
    
    bool isCommonPrefix(const vector<string> &strs, int length)
    {
        string str0 = strs[0].substr(0, length);
        int count = strs.size();
        for (int i = 0; i < count; ++i)
        {
            string str = strs[i];
            for (int j = 0; j < length; ++j)
            {
                if (str[j] != str0[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};