/**
 * 393. UTF-8 编码验证
 * 给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。
 * UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
 * 对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
 * 对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int i: data) {
            if (cnt) {
                if ((i & 0xC0) == 0x80) --cnt;
                else return false;
            } 
            else if ((i & 0xE0) == 0xC0) cnt = 1;
            else if ((i & 0xF0) == 0xE0) cnt = 2;
            else if ((i & 0xF8) == 0xF0) cnt = 3;
            else if ((i & 0x80) != 0) return false;
        }
        return !cnt;
    }
};
