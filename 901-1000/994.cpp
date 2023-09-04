/**
 * 994. 腐烂的橘子
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 * 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 */
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        deque<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) total++;
                else if (grid[i][j] == 2) q.push_back(make_pair(i, j));
            }
        }

        int res = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int k = 0; k < s; k++) {
                pair<int, int> orange = q.front();
                q.pop_front();

                int i = orange.first;
                int j = orange.second;
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    q.push_back(make_pair(i - 1, j));
                    total--;
                }
                if (i < m - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    q.push_back(make_pair(i + 1, j));
                    total--;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    q.push_back(make_pair(i, j - 1));
                    total--;
                }
                if (j < n - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    q.push_back(make_pair(i, j + 1));
                    total--;
                }
            }
            if (!q.empty()) res++;
        }
        
        return total > 0 ? -1 : res;
    }
};
