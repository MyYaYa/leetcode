class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        int s = intervals[0].start;
        int e = intervals[0].end;
        Interval tmp;
        for (auto i : intervals) {
            if (i.start > e) {
                result.push_back(Interval(s,e));
                s = i.start;
                e = max(i.end, e);
            } else {
                e = max(i.end, e);
            }
        }
        result.push_back(Interval(s, e));
        return result;
    }
};