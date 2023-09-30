/**
 * 763. 划分字母区间
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 * 返回一个表示每个字符串片段的长度的列表。
 */
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> partition;
        int left = 0;
        int right = 0;

        for (int i = 0; i < length; i++) {
            right = max(right, last[s[i] - 'a']);
            if (i == right) {
                partition.push_back(right - left + 1);
                left = right + 1;
            }
        }

        return partition;
    }
};
