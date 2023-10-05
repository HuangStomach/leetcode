/**
 * 1456. 定长子串中元音的最大数目
 * 给你字符串 s 和整数 k 。
 * 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
 * 英文中的 元音字母 为（a, e, i, o, u）。
 */
#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel_count = 0;

        for (int i = 0; i < k; ++i) {
            vowel_count += isVowel(s[i]);
        }

        int ans = vowel_count;
        for (int i = k; i < n; ++i) {
            vowel_count += isVowel(s[i]) - isVowel(s[i - k]);
            ans = max(ans, vowel_count);
        }
        return ans;
    }
};
