/** 
 * 628. 三个数的最大乘积
 * 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int res;
        if (nums[size - 1] > 0) {
            int left = nums[0] * nums[1];
            int right = nums[size - 2] * nums[size - 3];

            res = max(left, right) * nums[size - 1];
        }
        else res = nums[size - 2] * nums[size - 3] * nums[size - 1];
        return res;   
    }
};