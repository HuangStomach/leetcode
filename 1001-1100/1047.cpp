/**
 * 1047. 删除字符串中的所有相邻重复项
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 */
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string str;
        for (char ch : s) {
            if (!str.empty() && str.back() == ch) str.pop_back();
            else str.push_back(ch);
        }
        return str;
    }
};
