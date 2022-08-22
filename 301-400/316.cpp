/**
 * 316. 去除重复字母
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(26);
        vector<int> has(26);
        string res;
        
        for (int i = 0; i < s.size(); i++) {
            dict[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            if (has[s[i] - 'a']) continue;

            while (!res.empty() && res.back() > s[i] && dict[res.back() - 'a'] > i) {
                has[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(s[i]);
            has[s[i] - 'a'] = true;
        }
        
        return res;
    }
};
