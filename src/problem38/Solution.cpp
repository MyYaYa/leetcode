class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        queue<pair<char, int>> q;
        string last = countAndSay(n-1);
        int len = last.size();
        char tmp = last[0];
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (last[i] != tmp) {
                if (tmp != ' '){
                    q.push(pair<char,int>(tmp,count));
                    count = 1;
                    tmp = last[i];
                }
            } else {
                count++;
            }
            if (i == len-1){
                q.push(pair<char,int>(tmp,count));
            }
        }
        string result = "";
        while(!q.empty()) {
            result = result + to_string(q.front().second) + q.front().first;
            q.pop();
        }
        return result;
    }
};