/*
在一个数组中找到和为target的组合

用一个hash映射来表示出现数字的值和次数关系
再用回溯直接求出所有可能
采用两个措施来剪枝
1、判断当前选中的值是否大于target（或者剩余的值是否大于0）
2、选择的数的个数是否超出总体个数
*/

class Solution {
    vector<pair<int,int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;
public:
    void dfs(int pos, int rest){
        if(rest == 0){
            ans.push_back(sequence);
            return;
        }

        if (pos == freq.size() || rest < freq[pos].first){
            return;
        }

        dfs(pos+1, rest);
        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i){
            sequence.push_back(freq[pos].first);
            dfs(pos+1, rest-i*freq[pos].first);
        }
        for(int i = 1; i <= most; ++i){
            sequence.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int num : candidates){
            if (freq.empty() || num != freq.back().first){
                freq.emplace_back(num, 1);
            }
            else{
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};


/*
方法二使用排序来代替方法一的频率
*/

\class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	void backtrace(vector<int>& candidates, int target, int index) {
		if (0 == target) {
			res.push_back(tmp);
			return;
		}

		for (int i = index; i < candidates.size() && target - candidates[i] >= 0; ++i) {
			if (i > index && candidates[i] == candidates[i - 1]) {
				continue;
			}
			tmp.push_back(candidates[i]);
			backtrace(candidates, target - candidates[i], i + 1);
			tmp.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrace(candidates,  target, 0);
		return res;
	}
};
