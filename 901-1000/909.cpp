/**
 * 909. 蛇梯棋
 * 给你一个大小为 n x n 的整数矩阵 board ，方格按从 1 到 n2 编号，编号遵循 转行交替方式 ，从左下角开始 （即，从 board[n - 1][0] 开始）每一行交替方向。
 * 玩家从棋盘上的方格 1 （总是在最后一行、第一列）开始出发。
 * 每一回合，玩家需要从当前方格 curr 开始出发，按下述要求前进：
 * 选定目标方格 next ，目标方格的编号符合范围 [curr + 1, min(curr + 6, n2)] 。
 * 该选择模拟了掷 六面体骰子 的情景，无论棋盘大小如何，玩家最多只能有 6 个目的地。
 * 传送玩家：如果目标方格 next 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地。否则，玩家传送到目标方格 next 。 
 * 当玩家到达编号 n2 的方格时，游戏结束。
 * r 行 c 列的棋盘，按前述方法编号，棋盘格中可能存在 “蛇” 或 “梯子”；如果 board[r][c] != -1，那个蛇或梯子的目的地将会是 board[r][c]。编号为 1 和 n2 的方格上没有蛇或梯子。
 * 注意，玩家在每回合的前进过程中最多只能爬过蛇或梯子一次：就算目的地是另一条蛇或梯子的起点，玩家也 不能 继续移动。
 * 举个例子，假设棋盘是 [[-1,4],[-1,3]] ，第一次移动，玩家的目标方格是 2 。那么这个玩家将会顺着梯子到达方格 3 ，但 不能 顺着方格 3 上的梯子前往方格 4 。
 * 返回达到编号为 n2 的方格所需的最少移动次数，如果不可能，则返回 -1。
 */
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> vis(n * n + 1);

        queue<pair<int, int>> q;
        q.emplace(1, 0);
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int nxt = p.first + i;
                if (nxt > n * n) break;

                pair<int, int> rc = id2rc(nxt, n);
                if (board[rc.first][rc.second] > 0) nxt = board[rc.first][rc.second];
                if (nxt == n * n) return p.second + 1;

                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1); // 扩展新状态
                }
            }
        }
        return -1;
    }
};
