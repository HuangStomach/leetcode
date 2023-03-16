/**
 * 388. 文件的最长绝对路径
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void SplitString(const std::string &s, std::vector<std::string> &v, const std::string &c) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while (std::string::npos != pos2) {
            v.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length()) v.push_back(s.substr(pos1));
    }

    int lengthLongestPath(string s) {
        int res = 0;
        unordered_map<int, int> d;
        d[-1] = 0;
        vector<string> lines;
        SplitString(s, lines, "\n");
        for (string line : lines) {
            int depth = count(line.begin(), line.end(), '\t');
            d[depth] = d[depth - 1] + line.size() - depth;
            if (std::string::npos != line.find('.'))
            {
                res = max(res, d[depth] + depth);
            }
        }
        return res;
    }
};
