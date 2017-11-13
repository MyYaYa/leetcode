class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m==0)
            return vector<int>{};
        int n = matrix[0].size();
        if (n==0)
            return vector<int>{};
        vector<int> result;
        int m_low = 0;
        int m_high = m-1;
        int n_low = 0;
        int n_high = n-1;

        while (m_low<=m_high && n_low<=n_high) {
            for (int j = n_low; j <= n_high; j++) {
                result.push_back(matrix[m_low][j]);
            }
            m_low++;
            for (int i = m_low; i <= m_high; i++) {
                result.push_back(matrix[i][n_high]);
            }
            n_high--;
            if (m_low <= m_high) {
                for (int j = n_high; j >= n_low; j--) {
                    result.push_back(matrix[m_high][j]);
                }
            }
            m_high--;
            if (n_low <= n_high) {
                for (int i = m_high; i >= m_low; i--) {
                    result.push_back(matrix[i][n_low]);
                }
            }
            n_low++;
        }
        return result;
    }
};