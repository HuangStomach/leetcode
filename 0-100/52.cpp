/**
 * 52. N 皇后 II
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 */
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }

    int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) return 1;

        int count = 0;
        int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            // x & (−x) 可以获得 xxx 的二进制表示中的最低位的 111 的位置
            availablePositions = availablePositions & (availablePositions - 1);
            // x & (x−1) 可以将 xxx 的二进制表示中的最低位的 111 置成 000
            count += solve(
                n, row + 1, 
                columns | position, (diagonals1 | position) << 1, 
                (diagonals2 | position) >> 1
            );
        }
        return count;
    }
};
