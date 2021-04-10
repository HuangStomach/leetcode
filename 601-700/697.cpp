/** 
 * 697. 数组的度
 * 给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
 * 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int times[50000];
        int first[50000];
        int last[50000];

        int m = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (times[nums[i]]++ == 0) first[nums[i]] = i;
            m = max(m, times[nums[i]]);
            last[nums[i]] = i;
        }
        
        vector<int> v; 
        for (int i = 0; i <= 49999; ++i) if (times[i] == m) v.push_back(i);
        
        int res = 50000;
        for (int n : v) res = min(res, last[n] - first[n]);
        return res + 1;
    }
};
