/**
 * 944. 删列造序
 * 给你由 n 个小写字母字符串组成的数组 strs，其中每个字符串长度相等。
 * 这些字符串可以每个一行，排成一个网格。例如，strs = ["abc", "bce", "cae"] 可以排列为：
 * abc
 * bce
 * cae
 * 你需要找出并删除 不是按字典序升序排列的 列。在上面的例子（下标从 0 开始）中，列 0（'a', 'b', 'c'）和列 2（'c', 'e', 'e'）都是按升序排列的，而列 1（'b', 'c', 'a'）不是，所以要删除列 1 。
 * 返回你需要删除的列数。
 */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) return 0;
        int res = 0;
        int n = strs[0].length();
        int m = strs.size();

        for (int i = 0; i < n; i++) {
            int start = -1;
            for (int j = 0; j < m; j++) {
                if (strs[j][i] - '0' < start) {
                    res++;
                    break;
                }
                else start = strs[j][i] - '0';
            }
        }

        return res;
    }
};
