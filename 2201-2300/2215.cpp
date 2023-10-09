/**
 * 2215. 找出两数组的不同
 * 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，请你返回一个长度为 2 的列表 answer ，其中：
 * answer[0] 是 nums1 中所有 不 存在于 nums2 中的 不同 整数组成的列表。
 * answer[1] 是 nums2 中所有 不 存在于 nums1 中的 不同 整数组成的列表。
 * 注意：列表中的整数可以按 任意 顺序返回。
 */
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;   // nums1 与 nums2 所有元素的哈希集合
        for (int num: nums1) set1.insert(num);
        for (int num: nums2) set2.insert(num);

        vector<vector<int>> res(2);

        for (int num: set1) {
            if (!set2.count(num)) res[0].push_back(num);
        }
        for (int num: set2) {
            if (!set1.count(num)) res[1].push_back(num);
        }
        return res;
    }
};
