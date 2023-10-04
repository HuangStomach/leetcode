/**
 * 1679. K 和数对的最大数目
 * 给你一个整数数组 nums 和一个整数 k 。
 * 每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。
 * 返回你可以对数组执行的最大操作数。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        while(left < right) {
            if (nums[left] + nums[right] < k) left++;
            else if (nums[left] + nums[right] > k) right--;
            else {
                right--;
                left++;
                count++;
            }
        }
        return count;
    }
};
