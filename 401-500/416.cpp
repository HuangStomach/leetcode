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
        int sum = 0;
        for (int n : nums)  sum += n;
        if (sum % 2 != 0) return false;

        int weight = sum / 2;
        int dp[weight + 1];
        dp[0] = 1;
        for (int num : nums) {
            for (int i = weight; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[weight] != 0;
    }
};
