class Solution {
public:
    void Insert(int num)
    {
        // how many data now? determin which heap to insert
        if (((max.size() + min.size()) & 1) == 0) {
            // even, insert into min heap, but num is less than max heap
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());

                num = max[0];
                // pop_heap move the max num to the end.
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else {
            // odd, insert into max heap, but num is greater than min heap
            if (min.size() > 0 && num > min[0]) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                // pop_heap move the min num to the end.
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    {
        int size = max.size() + min.size();
        if (size == 0)  return 0.0;
        if ((size & 1) == 0) {
            return (double(max[0]) + double(min[0])) / 2;
        } else {
            return double(min[0]);
        }
    }

private:
    vector<int> max;
    vector<int> min;
};