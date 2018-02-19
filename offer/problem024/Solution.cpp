class Solution {
public:
    void push(int value) {
        stk.push(value);
        if (minStk.empty() || value < minStk.top()) {
            minStk.push(value);
        } else {
            int nowMin = minStk.top();
            minStk.push(nowMin);
        }
    }
    void pop() {
        stk.pop();
        minStk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};