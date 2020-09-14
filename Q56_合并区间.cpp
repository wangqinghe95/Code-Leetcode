/*
如果 merged 为空， 或者最后一堆区域的右值小于新区域的左值，就将新区域附加到二维数组最后
否则就需要判断最后一个区域的右值和合新区域的右值谁大取谁，替换旧区域的的右值

注意 vector的二维数组只能使用 size 来判断是非为空， 没有 empty
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return {};
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L)
            {
                merged.push_back({L,R});
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};