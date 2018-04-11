class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)   return -1;
        list<int> children;
        for (int i = 0; i < n ;++i) {
            children.push_back(i);
        }
        list<int>::iterator cur = children.begin();
        while (children.size() > 1) {
            for (int i = 0; i < m-1; ++i) {
                ++cur;
                if (cur == children.end())
                    cur = children.begin();
            }
            list<int>::iterator next = ++cur;
            if (next == children.end())
                next = children.begin();
            --cur;
            children.erase(cur);
            cur = next;
        }
        return *cur;
    }
};