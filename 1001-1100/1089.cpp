/**
 * 1089. 复写零
 * 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
 * 注意：请不要在超过该数组长度的位置写入元素。
 * 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
 */
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int n = arr.size(), i, j = n - 1, k = n - 1;
        for (i = 0; i < j; ++i) {
            if (arr[i] == 0) --j;
        }

        // 此处特判需要读者多加思考
        if (i == j && arr[i] == 0) arr[k--] = arr[j--];

        while (j >= 0) {
            if (arr[j] == 0) arr[k--] = 0;
            arr[k--] = arr[j--];
        }
    }
};
