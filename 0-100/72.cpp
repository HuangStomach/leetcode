/**
 * 72. 编辑距离
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 */
#include <string>

using namespace std;

class Solution {
public:
    int mindpistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n * m == 0) return n + m;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) dp[i][0] = i;
        for (int j = 0; j < m + 1; j++) dp[0][j] = j;

        // 计算所有 dpP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = dp[i - 1][j] + 1;
                int down = dp[i][j - 1] + 1;
                int left_down = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                dp[i][j] = min({ left, down, left_down });

            }
        }
        return dp[n][m];
    }
};
