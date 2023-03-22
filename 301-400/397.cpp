/**
 * 397. 整数替换
 * 给定一个正整数 n ，你可以做如下操作：
 * 如果 n 是偶数，则用 n / 2替换 n 。
 * 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
 * 返回 n 变为 1 所需的 最小替换次数 。
 */
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
private:
    unordered_map<int, int> counter;
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (counter.count(n)) return counter[n];


        if (n % 2 == 0) counter[n] = integerReplacement(n / 2) + 1;
        else counter[n] = min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)) + 2;

        return counter[n];
    }
};

int main(int argc, char *argv[], char *envp[] ) {
    Solution s;
    int res = s.integerReplacement(7);
    cout << res << endl;
}
