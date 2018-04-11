#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long Method(string s) {
        int len = s.size();
        vector<vector<long long>> dp(len, vector<long long>(len,0));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 1;
                }
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
        return dp[0][len - 1];
    }
};

int main()
{
    string s;
    cin >> s;
    Solution* sl =  new Solution();
    cout << sl->Method(s);
}