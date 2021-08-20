/**
 * 819. 最常见的单词
 * 给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。
 * 题目保证至少有一个词不在禁用列表中，而且答案唯一。
 * 禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。
 */
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

string mostCommonWord(string paragraph, vector<string> &banned) {
    paragraph += ' ';
    string temp = "";
    map<string, int> m;
    set<string> ban(banned.begin(), banned.end());
    for (char ch : paragraph) {
        if (isalpha(ch)) {
            temp += tolower(ch);
            continue;
        }
        
        if (!temp.empty()) {
            m[temp]++;
            temp.clear();
        }
    }
    vector<string> words;
    for (auto p : m) words.push_back(p.first);

    sort(words.begin(), words.end(), [&](string &s, string &p) { 
        return m[s] > m[p];
    });

    if (banned.empty()) return words[0];

    for (auto w : words) if (ban.find(w) == ban.end()) return w;
    return "";
}
