class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if (len == 0)
            return false;
        int root = sequence[len - 1];
        // left subtree
        int i = 0;
        // get the point just greater than root;
        for (;i < len - 1; i++) {
            if (sequence[i] > root)
                break;
        }
        // right subtree, check false situation
        int j = i;
        for (;j < len - 1; j++) {
            if (sequence[j] < root)
                return false;
        }
        bool left = true;
        if (i > 0)
            left = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin()+i));
        bool right = true;
        if (i < len - 1)
            right = VerifySquenceOfBST(vector<int>(sequence.begin()+i, sequence.end()-1));
        return left && right;
    }
};