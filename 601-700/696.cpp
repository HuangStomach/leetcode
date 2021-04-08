/** 
 * 696. 计数二进制子串
 * 给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。
 * 重复出现的子串要计算它们出现的次数。
 */
#include <string>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        char current = s.at(0);
        int last = -1;
        int num = 0;
        int res = 0;
        for (char c : s) {
            if (current != c) {
                if (last > 0) res += min(last, num);
                current = c;
                last = num;
                num = 1;
                continue;
            }
            current = c;
            num++;
        }
        
        if (last > 0) res += min(last, num);

        return res;
    }
};
