/**
 * 1005. K 次取反后最大化的数组和
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
 * 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
 * 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
 * 以这种方式修改数组后，返回数组 可能的最大和 。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int use = min(n, k);
        
        for (int i = 0; i < use && nums[i] < 0; i++) {
            nums[i] = -nums[i];
            --k;
        }

        sort(nums.begin(), nums.end());
        if (k % 2 != 0) nums[0] = -nums[0];

        int res = 0;
        for (int num : nums) res += num;

        return res;
    }
};
