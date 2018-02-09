class Solution
{
public:
    void push(int node) {
        if (queue1.empty()) {
            queue2.push(node);
        } else {
            queue1.push(node);
        }
    }

    int pop() {
        int temp;
        if (queue1.empty() && !queue2.empty()) {
            while (!queue2.empty()) {
                temp = queue2.front();
                queue2.pop();
                if (queue2.empty()) {
                    return temp;
                } else {
                    queue1.push(temp);
                }
            }
        } else if (!queue1.empty() && queue2.empty()) {
            while (!queue1.empty()) {
                temp = queue1.front();
                queue1.pop();
                if (queue1.empty()) {
                    return temp;
                } else {
                    queue2.push(temp);
                }
            }
        }
        temp = queue1.front();
        return temp;
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};