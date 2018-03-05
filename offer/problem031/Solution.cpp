class Solution {
public:
    char* Serialize(TreeNode *root) {
        // pre-order traversal
        if (!root)  return NULL;
        string str;
        Serialize(root, str);
        char* ret = new char[str.size()+1];
        int i = 0;
        for (; i < str.size(); i++) {
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode* root, string& str) {
        if (!root) {
            str += '#';
            str += ',';
            return;
        }
        str += to_string(root->val);
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
    TreeNode* Deserialize(char *str) {
        if (str == NULL)   return NULL;
        TreeNode* ret = Deserialize(&str);
        return ret;
    }

    TreeNode* Deserialize(char** str) {
        if (**str == '#') {
            (*str)++;
            (*str)++;
            return NULL;
        }
        int num = 0;
        while (**str != '\0' && **str != ',') {
            num = num * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode* root = new TreeNode(num);
        if (**str == '\0')
            return root;
        else
            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};