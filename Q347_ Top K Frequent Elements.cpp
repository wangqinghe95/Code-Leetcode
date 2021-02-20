//堆排序
//思路：key --> 数字，value --> 频率 保存到 unordered_map 中
//然后对key进行最大堆排序，排序的比较因素是 频率

class Solution {
public:
    void percdown(map<int, int> count, vector<int> &nums, int n, int i){
        int x =  nums[i] ;
        int child;
        for(; i*2+2 <= n; i = child){
            child = i * 2 + 1;
            if (child < n-1 && count[nums[child]] < count[nums[child+1]]){
                child++;
            }
            if (count[x] < count[ nums[ child ] ]){
                nums[ i ] = nums[ child ];
            }
            else{
                break;
            }
        }
        nums[ i ] = x;
    }

    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int, int> count;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            count[ nums[ i ] ]++;
        }  
        vector<int> heap;
        for (auto it = count.begin(); it != count.end(); ++it) {
                heap.push_back(it->first);
        }
        if (heap.size() < 2 || (heap.size() == k )){
            return heap;
        }
        for (int i = (heap.size() - 2)/2; i >= 0; --i){
            percdown(count, heap, heap.size(), i);
        }

        for (int i = heap.size() - 1; i >= heap.size()-k; --i){
            res.push_back(heap[ 0 ]);
            int temp = heap[ i ];
            heap[ i ] = heap[ 0 ];
            heap[ 0 ] = temp;
            percdown(count, heap, i, 0);
        }
        return res;
    } 
};


//桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            count[ nums[ i ] ]++;
        }
        vector<vector<int>> list(nums.size() + 1);
        for(auto it = count.begin(); it != count.end(); ++it){
            int key = it->second;
            list[ key ].push_back(it->first);
        }

        for (int i = list.size()-1; i >= 0 && res.size() < k; i--){
            if (list[i].size() == 0){
                continue;
            }
            for (int j = 0; j < list[ i ].size(); ++j){
                res.push_back(list[ i ][ j ]);
            }       
        }
        return res;
    }
};