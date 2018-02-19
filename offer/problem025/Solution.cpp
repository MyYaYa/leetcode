class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;
        if (pushV.empty() || popV.empty())
            return false;
        stack<int> stk;
        int pushIndex = 0;
        int popIndex = 0;
        while (pushIndex < pushV.size()) {
            if (stk.empty() || stk.top() != popV[popIndex]) {
                stk.push(pushV[pushIndex++]);
            } else if (stk.top() == popV[popIndex]) {
                stk.pop();
                popIndex++;
            }
        }
        while (!stk.empty() && stk.top() == popV[popIndex]) {
            stk.pop();
            popIndex++;
        }
        return stk.size() == 0;
    }
};