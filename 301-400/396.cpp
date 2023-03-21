/**
 * 396. 旋转函数
 * 给定一个长度为 n 的整数数组 nums 。
 * 假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
 * F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
 * 返回 F(0), F(1), ..., F(n-1)中的最大值 。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int sum = 0;
        int i;
        for (i = 0; i < n; i++) {
            sum += nums[i];
            cur += i * nums[i];
        }

        int res = cur;
        for (i = 1; i < n; i++) {
            cur += sum - n * nums[n - i];
            res = max(cur, res);
        }
        return res;
    }
};
