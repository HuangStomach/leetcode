/**
 * 1078. Bigram 分词
 * 给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。
 * 对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        int s = 0, e = 0, len = text.length();
        while (true) {
            while (s < len && text[s] == ' ') {
                s++;
            }
            if (s >= len) {
                break;
            }
            e = s + 1;
            while (e < len && text[e] != ' ') {
                e++;
            }
            words.push_back(text.substr(s, e - s));
            s = e + 1;
        }
        vector<string> ret;
        for (int i = 2; i < words.size(); i++) {
            if (words[i - 2] == first && words[i - 1] == second) {
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};
