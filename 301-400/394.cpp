/**
 * 394. 字符串解码
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        string stack;
        string repeat;
        int left = 0;

        for (char c : s) {
            if (isdigit(c)) {
                if (left > 0) stack.push_back(c);
                else {
                    repeat.push_back(c);
                    stack.clear();
                }
            }
            else if (c == '[') {
                left += 1;
                if (left > 1) stack.push_back(c);
            }
            else if (c == ']') {
                left -= 1;
                if (left > 0) {
                    stack.push_back(c);
                    continue;
                }
                string flatten = decodeString(stack);
                for (int i = 0; i < atoi(repeat.c_str()); i++) {
                    res.append(flatten);
                }
                repeat.clear();
            }
            else {
                if (repeat.size() > 0) stack.push_back(c);
                else res.push_back(c);
            }
        }
        
        return res;
    }
};

int main(int argc, char *argv[], char *envp[] ) {
    Solution s;
    string res = s.decodeString("100[leetcode]");
    cout << res << endl;
}
