/**
 * 884. 两句话中的不常见单词
 * 给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
 * 如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
 * 返回所有不常用单词的列表。
 * 您可以按任何顺序返回列表。 
 */
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> mymap;
        A = A + " " + B;
        istringstream words(A);
        string w;
        vector<string> ans;
        while (words >> w) ++mymap[w];
        for (auto m : mymap) if (m.second == 1) ans.push_back(m.first);
        return ans;
    }
};
