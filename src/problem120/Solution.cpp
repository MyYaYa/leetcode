class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> pre(1,0);
        vector<int> temp;
        for (int i = 0; i < rows; i++) {
            temp = vector<int>(i+1,0);
            temp[0] = pre.front() + triangle[i][0];
            for (int j=1; j < pre.size(); j++) {
                temp[j] = min(pre[j-1] + triangle[i][j], pre[j] + triangle[i][j]);
            }
            temp[i] = pre.back() + triangle[i][i];
            pre = temp;
        }
        sort(temp.begin(), temp.end());
        return temp.front();
    }
};