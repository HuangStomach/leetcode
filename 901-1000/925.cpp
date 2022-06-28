/**
 * 925. 长按键入
 * 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.length() || j < typed.length()) {
            char a = name[i];
            char b = typed[j];
            if (a != b) return false;

            int lenA = 0;
            int lenB = 0;
            for (int k = i; k < name.length(); k++) {
                if (name[k] == a) lenA++;
                else break;
            }
            
            for (int k = j; k < typed.length(); k++) {
                if (typed[k] == b) lenB++;
                else break;
            }

            if (lenA > lenB) return false;
            i += lenA;
            j += lenB;
        }

        return i == name.length() && j == typed.length();
    }
};
