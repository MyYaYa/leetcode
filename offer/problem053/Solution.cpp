class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty())    return false;
        sort(numbers.begin(), numbers.end());
        int i = 0;
        while (numbers[i] == 0) ++i;
        int numOf0 = i;
        int dist = 0;
        for (i += 1; i < numbers.size(); ++i) {
            if (numbers[i] == numbers[i-1])
                return false;
            dist += (numbers[i] - numbers[i-1] - 1);
            if (dist > numOf0)
                return false;
        }
        return true;
    }
};