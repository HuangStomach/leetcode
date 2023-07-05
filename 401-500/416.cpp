/**
 * 416. 分割等和子集
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0, maxNum = 0;
        for (int n : nums)  {
            sum += n;
            maxNum = max(maxNum, n);
        }
        if (sum % 2 != 0) return false;

        int weight = sum / 2;
        if (maxNum > weight) return false;

        vector<int> dp(weight + 1, 0);
        dp[0] = true;
        for (int num : nums) {
            for (int j = weight; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[weight];
    }
};
