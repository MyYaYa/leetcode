#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Method(int step, int& X, int& Y) {
        int result = 0;
        vector<vector<vector<int>>> dp(step+1, vector<vector<int>>(9, vector<int>(9, 0)));
        dp[1][2][1] = 1;
        dp[1][1][2] = 1;
        for (int i = 2; i <= step; ++i) {
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < 9; ++k) {
                    int tmp = 0;
                    if (j-2>=0 && j-2<=8 && k-1>=0 && k-1<=8)
                        tmp += dp[i-1][j-2][k-1];
                    if (j-2>=0 && j-2<=8 && k+1>=0 && k+1<=8)
                        tmp += dp[i-1][j-2][k+1];
                    if (j+2>=0 && j+2<=8 && k-1>=0 && k-1<=8)
                        tmp += dp[i-1][j+2][k-1];
                    if (j+2>=0 && j+2<=8 && k+1>=0 && k+1<=8)
                        tmp += dp[i-1][j+2][k+1];
                    if (j-1>=0 && j-1<=8 && k-2>=0 && k-2<=8)
                        tmp += dp[i-1][j-1][k-2];
                    if (j-1>=0 && j-1<=8 && k+2>=0 && k+2<=8)
                        tmp += dp[i-1][j-1][k+2];
                    if (j+1>=0 && j+1<=8 && k-2>=0 && k-2<=8)
                        tmp += dp[i-1][j+1][k-2];
                    if (j+1>=0 && j+1<=8 && k+2>=0 && k+2<=8)
                        tmp += dp[i-1][j+1][k+2];
                    dp[i][j][k] = tmp % 1000000007;
                }
            }
        }
        return dp[step][X][Y];
    }
};

int main()
{
    int step;
    int X, Y;
    cin >> step;
    cin >> X >> Y;
    Solution* sl =  new Solution();
    cout << sl->Method(step, X, Y);
}
