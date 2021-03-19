/** 
 * 643. 子数组最大平均数 I
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 */
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int current = sum;
        
        for (int i = k; i < nums.size(); i++) {
            current = current - nums[i - k] + nums[i];
            if (sum < current) sum = current;
        }
        
        return double(sum) / k;
    }
};