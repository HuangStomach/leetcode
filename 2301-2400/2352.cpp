/**
 * 2352. 相等行列对
 * 给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。
 * 如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
 */
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt;
        for (auto row : grid) {
            cnt[row]++;
        }

        int res = 0;
        for (int j = 0; j < n; j++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                arr.emplace_back(grid[i][j]);
            }
            if (cnt.find(arr) != cnt.end()) {
                res += cnt[arr];
            }
        }
        return res;
    }
};
