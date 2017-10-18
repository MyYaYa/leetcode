class Solution {
public:
    class Cmp{
    public:
        bool operator() (pair<string, int> a, pair<string, int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        int n = words.size();
        if (k <= 0 || n == 0)
            return ans;
        map<string, int> result;
        for (int i = 0; i < n; i++) {
            result[words[i]]++;
        }
        priority_queue<pair<string,int>, vector<pair<string, int>>, Cmp> pq;
        for (auto a : result) {
            pq.push(a);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};