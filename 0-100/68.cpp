#include <vector>
#include <string>

/**
 * 68. 文本左右对齐
 * 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 */
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> temps;

        int current = 0;
        for (string word: words) {
            if (current + word.size() > maxWidth) {
                int remain = maxWidth - current + temps.size();
                int base = max(1, (int)(temps.size() - 1));
                int a = remain / base;
                int b = remain % base;

                string t;
                for (int i = 0; i < temps.size(); ++i) {
                    t.append(temps[i]);
                    if (i == 0 || i != temps.size() - 1) t.append(a, ' ');
                    if (b-- > 0) t.append(" ");
                }
                res.push_back(t);
                temps.clear();
                current = 0;
            }
            temps.push_back(word);
            current += word.size() + 1;
        }

        string t;
        for (int i = 0; i < temps.size(); ++i) {
            t.append(temps[i]);
            if (i != temps.size() - 1) t.append(" ");
        }
        temps.clear();
        int remain = maxWidth - t.size();
        t.append(remain, ' ');
        res.push_back(t);
        return res;
    }
};
