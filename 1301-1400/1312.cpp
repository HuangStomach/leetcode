/**
 * 1312. 让字符串成为回文串的最少插入次数
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 * 请你返回让 s 成为回文串的 最少操作次数 。
 * 「回文串」是正读和反读都相同的字符串。
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t(s.rbegin(), s.rend());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        return n - dp[n][n];
    }
};
