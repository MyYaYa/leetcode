class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0])) stk.push(stoi(tokens[i]));
            else {
                int v2 = stk.top();
                stk.pop();
                int v1 = stk.top();
                stk.pop();
                switch (tokens[i][0]) {
                    case '+' : v1 += v2; break;
                    case '-' : v1 -= v2; break;
                    case '/' : v1 /= v2; break;
                    case '*' : v1 *= v2; break;
                }
                stk.push(v1);
            }
        }
        return stk.top();
    }
};