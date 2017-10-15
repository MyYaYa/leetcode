class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int right=n, left=n;
        string path = "";
        vector<string> result;
        next(right, left, path, result);
        return result;
    }
private:
    void next(int right, int left, string path, vector<string> &result) {
        if (right == 0 && left == 0) {
            result.push_back(path);
            return;
        }
        if (right != 0) {
            next(right-1, left, path+"(", result);
        }
        if (left != 0 && left > right) {
            next(right, left-1, path+")", result);
        }
    }
};