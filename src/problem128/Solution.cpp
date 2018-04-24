class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())    return 0;
        unordered_set<int> st(num.begin(), num.end());
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (st.find(num[i]) == st.end()) continue;
            int l = num[i], r = num[i];
            st.erase(num[i]);
            while (st.find(l-1) != st.end())
                st.erase(--l);
            while (st.find(r+1) != st.end())
                st.erase(++r);
            res = max(res, (r-l+1));
        }
        return res;
    }
};
