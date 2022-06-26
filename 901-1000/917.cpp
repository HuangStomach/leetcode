/**
 * 917. 仅仅反转字母
 * 给你一个字符串 s ，根据下述规则反转字符串：
 * 所有非英文字母保留在原有位置。
 * 所有英文字母（小写或大写）位置反转。
 * 返回反转后的 s 。
 */
#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) left++;
            while (right > left && !isalpha(s[right])) right--;

            if (left >= right) break;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
