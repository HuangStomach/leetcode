/** 
 * 661. 图片平滑器
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int height = M.size();
        int width = M[0].size();
        vector<vector<int>> res = vector(height, vector<int>(width));
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int sum = M[i][j];
                int num = 1;
                if (i > 0 && j > 0) {
                    sum += M[i - 1][j - 1];
                    num++;
                }
                if (i > 0) {
                    sum += M[i - 1][j];
                    num++;
                }
                if (i > 0 && j < width - 1) {
                    sum += M[i - 1][j + 1];
                    num++;
                }
                if (j > 0) {
                    sum += M[i][j - 1];
                    num++;
                }
                if (j < width - 1) {
                    sum += M[i][j + 1];
                    num++;
                }
                if (i < height - 1 && j > 0) {
                    sum += M[i + 1][j - 1];
                    num++;
                }
                if (i < height - 1) {
                    sum += M[i + 1][j];
                    num++;
                }
                if (i < height - 1 && j < width - 1) {
                    sum += M[i + 1][j + 1];
                    num++;
                }
                res[i][j] = sum / num;
            }
        }
        return res;
    }
};
