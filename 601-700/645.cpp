/** 
 * 645. 错误的集合
 * 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。
 * 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        vector<int> t(nums.size(), 0);

        for (int i : nums) t[i - 1]++;

        for (int i = 0; i < nums.size(); i++) {
            if (t[i] == 0) res[1] = i + 1;
            else if (t[i] == 2) res[0] = i + 1;
        }
        
        return res;
    }
};
