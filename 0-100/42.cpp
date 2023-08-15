/**
 * 42. 接雨水
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;

        int res = 0;
        stack<pair<int, int>> s = stack<pair<int, int>>();
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] == 0) continue;
              
            int floor = 0;
            while (!s.empty() && s.top().second <= height[i]) {
                res += (i - s.top().first - 1) * (s.top().second - floor);
                floor += s.top().second - floor;
                s.pop();
            }

            if (s.empty()) {
                s.push(make_pair(i, height[i]));
                continue;
            }

            auto top = s.top();
            int h = s.top().second;
            res += (i - top.first - 1) * (height[i] - floor);
            s.push(make_pair(i, height[i]));
        }
        return res;
    }
};
