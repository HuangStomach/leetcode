/**
 * 937. 重新排列日志文件
 * 给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。
 * 有两种不同类型的日志：
 * 字母日志：除标识符之外，所有字均由小写字母组成
 * 数字日志：除标识符之外，所有字均由数字组成
 * 请按下述规则将日志重新排序：
 * 所有 字母日志 都排在 数字日志 之前。
 * 字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
 * 数字日志 应该保留原来的相对顺序。
 * 返回日志的最终顺序。
 */
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string & log1, const string & log2) {
            int pos1 = log1.find_first_of(" ");
            int pos2 = log2.find_first_of(" ");
            bool isDigit1 = isdigit(log1[pos1 + 1]);
            bool isDigit2 = isdigit(log2[pos2 + 1]);
            if (isDigit1 && isDigit2) {
                return false;
            }
            if (!isDigit1 && !isDigit2) {
                string s1 = log1.substr(pos1);
                string s2 = log2.substr(pos2);
                if (s1 != s2) {
                    return s1 < s2;
                }
                return log1 < log2;
            }
            return isDigit1 ? false : true;
        });
        return logs;
    }
};
