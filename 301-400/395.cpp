/**
 * 395. 至少有 K 个重复字符的最长子串
 * 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k <= 1) return s.size();
        if (s.empty() || s.size() < k) return 0;
        
        vector<int> hash(128, 0);
        for (char c : s) ++hash[c];
        
        int i = 0;
        while (i < s.size() && hash[s[i]] >= k) ++i;
        if (i == s.size()) return s.size();

        int l = longestSubstring(s.substr(0, i), k);
        while (i < s.size() && hash[s[i]] < k) ++i;
        int r = longestSubstring(s.substr(i), k);
        
        return max(l, r);
    }
};
