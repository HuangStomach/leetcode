/**
 * 76. 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 注意：
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 */
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, smap;
        int left = 0;
        int correct = 0;
        string res = s + ".";
        for (auto item : t) ++tmap[item];

        for (int right = 0; right < s.size(); ++right) {
            ++smap[s[right]];

            if (tmap[s[right]] >= smap[s[right]]) ++correct;

            // 字符串最短是空串 && 如果left对应的字符是冗余，那么进行右移删除
            while (left < right && smap[s[left]] > tmap[s[left]]) --smap[s[left++]];

            if (correct != t.size()) continue;
            if (right - left + 1 < res.size()) res = s.substr(left, right - left + 1);

        }
        return res.size() > s.size() ? "" : res;
    }
};
