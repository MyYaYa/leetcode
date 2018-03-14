struct RBTreeNode {
    friend class RBTree;
    int getKey() {
        return key;
    }

private:
    int key;
    bool color; // red is true, black is false
    RBTreeNode* left, * right, * parent;

};

class RBTree {
public:
    RBTree() : nil(new RBTreeNode()), root(nil) {
        nil->left = 0;
        nil->right = 0;
        nil->parent = 0;
        nil->color = false; // nil's color is black
    };
    void insert(int key);
    RBTreeNode* search(int key);
    void erase(int key);

private:
    void leftRotate(RBTreeNode* );
    void rightRotate(RBTreeNode* );
    void rbDelete(RBTreeNode* );
    void rbDeleteFixup(RBTreeNode* );
    void rbInsertFixup(RBTreeNode* );
    RBTreeNode* successor(RBTreeNode* );

    RBTreeNode* nil;    // T.nil
    RBTreeNode* root;   // tree's root node
};