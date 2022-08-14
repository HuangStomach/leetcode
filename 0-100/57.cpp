/**
 * 57. 插入区间
 * 给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> res;

        for (const vector<int> & interval: intervals) {
            if (interval[0] > right) {
                if (!placed) {
                    res.push_back({left, right}); // 代表已经超过了newInterval的范围，直接插入
                    placed = true;
                }
                res.push_back(interval);
            }
            else if (interval[1] < left) res.push_back(interval);
            else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        if (!placed) res.push_back({left, right});
        return res;
    }
};
