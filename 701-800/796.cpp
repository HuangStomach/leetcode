/**
 * 796. 旋转字符串
 * 给定两个字符串, A 和 B。
 * A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。
 */
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        s += s;
        return s.find(goal) != string::npos;
    }
};
