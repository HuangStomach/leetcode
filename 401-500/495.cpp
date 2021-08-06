/**
 * 495. 提莫攻击
 * 在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。
 * 你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;

        int res = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            res += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        return res + duration;
    }
};