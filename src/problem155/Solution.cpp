class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int x) {
        if (data.empty()) {
            data.push(x);
            support.push(x);
        } else {
            int m = support.top();
            data.push(x);
            support.push(min(x, m));
        }
    }

    void pop() {
        data.pop();
        support.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return support.top();
    }

private:
    stack<int> data;
    stack<int> support;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */