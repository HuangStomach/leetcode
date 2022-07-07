/**
 * 941. 有效的山脉数组
 * 给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int N = arr.size();
        if (N < 3) return false;

        int i = 0;
        while (i + 1 < N && arr[i] < arr[i + 1]) i++;
        if (i == 0 || i == N - 1) return false;
        while (i + 1 < N && arr[i] > arr[i + 1]) i++;

        return i == N - 1;
    }
};
