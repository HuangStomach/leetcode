/**
 * 2390. 从字符串中移除星号
 * 给你一个包含若干星号 * 的字符串 s 。
 * 在一步操作中，你可以：
 * 选中 s 中的一个星号。
 * 移除星号 左侧 最近的那个 非星号 字符，并移除该星号自身。
 * 返回移除 所有 星号之后的字符串。
 */
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == '*') st.pop();
            else st.push(c);
        }

        string res;
        int count = st.size();
        for (int i = 0; i < count; i++) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};