#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int NumOfPut(vector<int>& snacks, int q, int W, long long total) {
        if (q < 0){
            return 1;
        }
        int u = 0;
        if (W >= total){
            return pow(2, q+1);
        }
        if (W - snacks[q] >= 0){
            u += NumOfPut(snacks, q-1, W-snacks[q], total-snacks[q]);
        }
        u += NumOfPut(snacks, q-1, W, total-snacks[q]);
        return u;
    }
};

int main() {
    int n, W;
    cin >> n >> W;
    long long total = 0;
    vector<int> snacks(n, 0);
    for (int i = 0; i < n; i++)  {
        cin >> snacks[i];
        total += snacks[i];
    }
    sort(snacks.begin(), snacks.end());
    Solution* s = new Solution();
    cout << s->NumOfPut(snacks, n-1, W, total) << endl;
}