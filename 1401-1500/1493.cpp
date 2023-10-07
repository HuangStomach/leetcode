/**
 * 1493. 删掉一个元素以后全为 1 的最长子数组
 * 给你一个二进制数组 nums ，你需要从中删掉一个元素。
 * 请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
 * 如果不存在这样的子数组，请返回 0 。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;

        int left = 0;
        int right = 0;
        int zero = 0;

        for (; right < nums.size(); right++) {
            if (nums[right] == 0) zero++;
            while (zero > 1) {
                if (nums[left++] == 0) --zero;
            }
            res = max(res, right - left);
        }
        
        return res;
    }
};
