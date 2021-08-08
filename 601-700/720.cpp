/**
 * 720. 词典中最长的单词 
 * 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
 * 若无答案，则返回空字符串。
 */
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> S(words.begin(), words.end());
        string res = "";

        for (string str: words) {
            bool flag = true;          

            for (int i = 0; i < str.size() - 1; ++i) {
                string pre = str.substr(0, i + 1);
                if (!S.count(pre)) {
                    flag = false;
                    break;
                }
            }

            if (!flag) continue;
            if (res.empty()) res = str;
            else if (str.size() > res.size()) res = str;
            else if (str.size() == res.size() && str < res) res = str;
        }

        return res;
    }
};