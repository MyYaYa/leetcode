class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        vector<int> uglys = {1};
        int uglyCount = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        int m2 = 2 * uglys[t2];
        int m3 = 3 * uglys[t3];
        int m5 = 5 * uglys[t5];
        while (uglyCount < index) {
            while (m2 <= uglys[uglyCount-1]) {
                m2 = 2 * uglys[++t2];
            }
            while (m3 <= uglys[uglyCount-1]) {
                m3 = 3 * uglys[++t3];
            }
            while (m5 <= uglys[uglyCount-1]) {
                m5 = 5 * uglys[++t5];
            }
            // here m2, m3, m5 is greater than the present ugly.
            int m = min(min(m2, m3), m5);
            uglys.push_back(m);
            ++uglyCount;
        }
        return uglys[uglyCount-1];
    }
};