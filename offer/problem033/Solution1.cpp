class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())    return 0;
        int save = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] == save)
                times++;
            else {
                if (times == 0) {
                    save = numbers[i];
                    times = 1;
                } else {
                    times--;
                }
            }
        }
        times = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == save)
                times++;
        }
        return times > numbers.size() / 2 ? save : 0;
    }
};