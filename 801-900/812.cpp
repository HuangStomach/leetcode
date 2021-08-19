/**
 * 812. 最大三角形面积
 * 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
 * 鞋带儿公式 S三角形 = 0.5 * ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3* x1)) 
 */
#include <vector>

using namespace std;

class Solution {
private:
    double Area(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        return 0.5 * abs((a[0] * b[1] + b[0] * c[1] + c[0] * a[1]) - (a[1] * b[0] + b[1] * c[0] + c[1] * a[0]));
    }

public:
    double largestTriangleArea(vector<vector<int>> &points) {
        double res = 0.0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    res = max(res, Area(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
};