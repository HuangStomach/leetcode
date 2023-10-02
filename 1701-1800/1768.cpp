/**
 * 1768. 交替合并字符串
 * 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
 * 返回 合并后的字符串 。
 */
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        
        string ans;
        ans.reserve(m + n); // 要求更改string字符串的容量
        while (i < m || j < n) {
            if (i < m) ans.push_back(word1[i++]);
            if (j < n) ans.push_back(word2[j++]);
        }
        return ans;
    }
};
