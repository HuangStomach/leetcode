/**
 * 357. 统计各位数字都不同的数字个数
 * 给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int ans = 10, cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur *= 9 - i;
            ans += cur;
        }
        return ans;
    }
};
