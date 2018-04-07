class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        if (size <= 0 || num.empty() || num.size() < size)  return result;
        deque<int> window;
        for (int i = 0; i < size; ++i) {
            while (!window.empty() && num[i] >= num[window.back()])
                window.pop_back();
            window.push_back(i);
        }
        for (int i = size; i < num.size(); ++i) {
            result.push_back(num[window.front()]);
            while (!window.empty() && num[i] >= num[window.back()]) {
                window.pop_back();
            }
            if (!window.empty() && window.front() <= (int)(i-size)) {
                window.pop_front();
            }
            window.push_back(i);
        }
        result.push_back(num[window.front()]);
        return result;
    }
};