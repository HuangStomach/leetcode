/**
 * 97. 交错字符串
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
 * 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector<int>(s2.size() + 1, false);

        int n = s1.size();
        int m = s2.size();
        int t = s3.size();

        if (n + m != t) return false;

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) f[j] &= (s1[i - 1] == s3[p]);
                if (j > 0) f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
            }
        }

        return f[m];
    }
};
