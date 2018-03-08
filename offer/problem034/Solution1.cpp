class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k == 0 || k > input.size())  return vector<int>();
        priority_queue<int> pq;
        for (int i = 0; i < input.size(); i++) {
            if (pq.size() < k) {
                pq.push(input[i]);
            } else {
                int max_num = pq.top();
                if (max_num > input[i]) {
                    pq.pop();
                    pq.push(input[i]);
                }
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

// self-defined comp
template <class T>
class Compare {
public:
    bool operater() (T a, T b) {
        if (a < b)
            return true;
        else
            return false;
    }
};