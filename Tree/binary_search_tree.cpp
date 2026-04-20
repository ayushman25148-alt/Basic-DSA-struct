// Binary Search Tree - Basic Implementation
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    bool search(TreeNode* node, int val) {
        if (!node) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int val) {
        if (!node) return nullptr;
        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            // Node with one or no child
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: get inorder successor
            TreeNode* successor = findMin(node->right);
            node->data = successor->data;
            node->right = deleteNode(node->right, successor->data);
        }
        return node;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void destroyTree(TreeNode* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    void insert(int val)       { root = insert(root, val); }
    bool search(int val)       { return search(root, val); }
    void deleteNode(int val)   { root = deleteNode(root, val); }
    void inorder()             { inorder(root); cout << endl; }
    void preorder()            { preorder(root); cout << endl; }
    void postorder()           { postorder(root); cout << endl; }
    int height()               { return height(root); }

    ~BST() { destroyTree(root); }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder (sorted):  ";
    tree.inorder();

    cout << "Preorder:          ";
    tree.preorder();

    cout << "Postorder:         ";
    tree.postorder();

    cout << "Height of tree: " << tree.height() << endl;

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    tree.deleteNode(30);
    cout << "After deleting 30, Inorder: ";
    tree.inorder();

    return 0;
}
