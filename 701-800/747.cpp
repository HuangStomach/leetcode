/**
 * 747. 至少是其他数字两倍的最大数
 * 给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
 * 请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() <= 0) return -1;
        if (nums.size() == 1) return 0;

        int fst = max(nums[0], nums[1]);
        int index = nums[0] == fst ? 0 : 1;
        int sec = min(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > fst) {
                index = i;
                sec = fst;
                fst = num;
            }
            else if (num < fst && num > sec) sec = num;
        }

        return (fst >= sec * 2) ? index : -1;
    }
};