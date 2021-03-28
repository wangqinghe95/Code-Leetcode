/*
杨辉三角的问题：
杨辉三角的规律在于：
下一行的第二个值开始，是上一行的第 i-1，i 数的和
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i){
            res[ i ].resize(i + 1);
            res[ i ][ 0 ] = res[i][i]= 1;
            for (int j = 1; j < i; ++j){
                res[ i ][ j ] = res[ i - 1 ][ j ] + res[ i - 1 ][ j - 1 ];
            }
        }
        return res;
    }
};