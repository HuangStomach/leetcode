/**
 * 1108. IP 地址无效化
 * 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
 * 所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
 */
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (char & c : address) {
            if (c == '.') res.append("[.]");
            else res.push_back(c);
        }
        return res;
    }
};
