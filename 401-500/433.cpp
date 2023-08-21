/**
 * 433. 最小基因变化
 * 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
 * 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
 * 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
 * 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
 * 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
 * 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        unordered_map<string, int> mp;
        for (const auto &b : bank) mp[b] = 0;

        if (mp.count(end) == 0) return -1;
        if (start == end) return 0;

        queue<string> q1({start}), q2({end});
        int step = 0;
        const char table[4] = {'A', 'C', 'G', 'T'};

        for (mp[start] |= 1, mp[end] |= 2; q1.size() && q2.size(); ++step) {
            bool first = q1.size() < q2.size();
            queue<string> &q = first ? q1 : q2;
            int flag = first ? 1 : 2; // 此次遍历的方式

            for (int n = q.size(); n--; q.pop()) {
                string temp = q.front();
                if (mp[temp] == 3) return step; // 由于 mp 中进行了位运算 等于3就表示都来过
                for (int i = 0; i < temp.size(); ++i) {
                    for (int j = 0; j < 4; ++j) {
                        string s = temp;
                        if (s[i] == table[j]) continue;

                        s[i] = table[j];
                        if (mp.count(s) == 0 || mp[s] & flag) continue;

                        mp[s] |= flag;
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};
