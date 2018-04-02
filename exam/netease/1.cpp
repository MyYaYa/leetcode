#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    int LastTime(vector<int> clock_vector, int x, int class_time){
        int cur_time = INT32_MAX;
        for(auto clock : clock_vector){
            if(clock > class_time - x){
                cur_time = min(cur_time, 24 * 60 -(class_time - clock));
            }
            else{
                cur_time = min(cur_time, class_time - clock);
            }
        }
        return cur_time;
    }
};


int main() {
    int clock_num;
    cin >> clock_num;

    vector<int> clock_vector;
    for(;clock_num > 0;clock_num--){
        int hour,min;
        cin >> hour >> min;
        clock_vector.push_back((hour - 0) * 60 + min);
    }

    int x;
    cin >> x;

    int number_A, number_B;
    cin >> number_A >> number_B;
    int classTime = (number_A - 0) * 60 + number_B;

    int latestTime = Solution().LastTime(clock_vector, x, classTime);

    int output_min = (classTime - latestTime) % 60;
    int output_hour = ((classTime - latestTime) / 60 + 24) % 24;
    cout << output_hour << " " << output_min;

    return 0;
}