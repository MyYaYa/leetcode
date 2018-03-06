/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)  return "";
        string result;
        serialize(root, result);
        return result;
    }

    void serialize(TreeNode* root, string& result) {
        if (!root)  {
            result += '#';
            result += ',';
        } else {
            result += (to_string(root->val) + ',');
            serialize(root->left, result);
            serialize(root->right, result);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())   return NULL;
        return myDeserialize(data);
    }

    TreeNode* myDeserialize(string& data) {
        if (data[0] == '#') {
            if (data.size() > 1)
                data = data.substr(2);
            return NULL;
        }
        else {
            int pos = data.find(',');
            int num = stoi(data.substr(0, pos));
            data = data.substr(pos+1);
            TreeNode* root = new TreeNode(num);
            root->left = myDeserialize(data);
            root->right = myDeserialize(data);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));