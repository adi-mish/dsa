#include <iostream>
using namespace std;

// Tree Node
template <typename T>
struct TreeNode {
    T data;
    TreeNode* leftNode;
    TreeNode* rightNode;

    TreeNode(T value, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr)
       : data(value), leftNode(leftNode), rightNode(rightNode) {}
};

// Binary Search Tree
template <typename T>
class BST {
private:
    TreeNode<T>* root;

    TreeNode<T>* insert(TreeNode<T>* root, T value) {
        if (root == nullptr)
            return new TreeNode<T>(value);

        if (value < root->data)
            root->leftNode = insert(root->leftNode, value);
        else if (value > root->data)
            root->rightNode = insert(root->rightNode, value);

        return root;
    }

    void inorderTraversal(TreeNode<T>* root) {
        if (root != nullptr) {
            inorderTraversal(root->leftNode);
            cout << root->data << endl;
            inorderTraversal(root->rightNode);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }
};


int main() {
    BST<int> bst1;
    bst1.insert(4);
    bst1.insert(5);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(3);
    bst1.inorderTraversal();
    return 0;
}
