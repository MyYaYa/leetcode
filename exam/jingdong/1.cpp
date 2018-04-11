#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void print(vector<long long>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 1) {
                cout << "No" << endl;
                continue;
            }
            long long  x = 0, y = 0;
            for (long long j = 2; j <= nums[i] / 3; j=j+2) {
                if (nums[i] % j == 0) {
                    if ((nums[i] / j) % 2 == 1) {
                        y = j;
                        x = nums[i] / j;
                        break;
                    }
                }
            }
            if (x && y)
                cout << x << " " << y << endl;
            else
                cout << "No" << endl;
        }
    }
};

int main() {
    Solution* s = new Solution();
    int cols;
    cin >> cols;
    vector<long long> nums(cols);
    for (int i = 0; i < cols; ++i) {
        cin >> nums[i];
    }
    s->print(nums);
}