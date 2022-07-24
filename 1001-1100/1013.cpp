/**
 * 1013. 将数组分成和相等的三个部分
 * 给你一个整数数组 arr，只有可以将其划分为三个和相等的 非空 部分时才返回 true，否则返回 false。
 * 形式上，如果可以找出索引 i + 1 < j 且满足 (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1]) 就可以将数组三等分。
 */
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) return false;
        int unit = sum / 3;

        int left = arr[0];
        int right = arr[arr.size() - 1];
        int i = 1;
        int j = arr.size() - 2;
        
        while (j > i) {
            if (left != unit) left += arr[i++];
            if (right != unit) right += arr[j--];
            
            if (right == unit && left == unit && j >= i) return true;
        }
        return false;
    }
};