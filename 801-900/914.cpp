/**
 * 914. 卡牌分组
 * 给定一副牌，每张牌上都写着一个整数。
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 每组都至少有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * 仅当你可选的 X >= 2 时返回 true。
 */
#include <vector>

using namespace std;

class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for (auto x: deck) cnt[x]++;
        int g = -1;
        for (int i = 0; i < 10000; ++i) {
            if (!cnt[i]) continue;
            g = ~g ? gcd(g, cnt[i]) : g = cnt[i];
        }
        return g >= 2;
    }
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};
