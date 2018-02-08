class Solution
{
public:
    void push(int node) {
        if (stack1.empty()) {
            while (!stack2.empty()) {
                int v = stack2.top();
                stack2.pop();
                stack1.push(v);
            }
            stack1.push(node);
        } else
            stack1.push(node);
    }

    int pop() {
        int v;
        if (stack1.empty()) {
            v = stack2.top();
            stack2.pop();
        } else {
            while (!stack1.empty()) {
                int v = stack1.top();
                stack1.pop();
                stack2.push(v);
            }
            v = stack2.top();
            stack2.pop();
        }
        return v;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};