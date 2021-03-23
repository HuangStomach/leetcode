/** 
 * 680. 验证回文字符串 Ⅱ
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 */
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int count = 0;
        int length = s.size();
        for (int i = 0, j = length - 1; i < j; i++, j--) {
            if (s.at(i) != s.at(j)) {
                return valid(s, i + 1, j) || valid(s, i, j - 1);
            }
        }
        return true;
    }
    
    bool valid(string s, int i, int j){
        while (i < j) {
            if (s.at(i) != s.at(j)) return false;
            i++;
            j--;
        }
        return true;
    }
};