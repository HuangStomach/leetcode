/**
 * 821. 字符的最短距离
 * 给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
 * 返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。
 * 两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。
 */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos(S.size(), -1);

        int pre = -1;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == C) {
                pre = i;
                pos[i] = 0;
            }
            else if (pre != -1) pos[i] = pre - i;
        }
        
        pre = -1;
        for (int i = 0; i < S.size(); i++) {
            if (pre != -1) pos[i] = min(i - pre, pos[i]);
            if (pos[i] == -1) pos[i] = i - pre;
            if (S[i] == C) pre = i;
        }
        return pos;
    }
};
