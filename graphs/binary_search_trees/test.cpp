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

// Method for in order traversal of a BST. It traverses the nodes in a sorted order. Left -> Root -> Right.
    void inorderTraversal(TreeNode<T>* root) {
        if (root != nullptr) {
            inorderTraversal(root->leftNode);
            cout << root->data << endl;
            inorderTraversal(root->rightNode);
        }
    }

// Method for preorder traversal of a BST. Useful to reconstruct a BST. Root -> Left -> Right.
    void preOrderTraversal(TreeNode<T>* root) {
        if (root != nullptr) {
            cout << root->data << endl;
            preOrderTraversal(root->leftNode);
            preOrderTraversal(root->rightNode);
        } 
    }

// Method for in order traversal of a BST. Left -> Right -> Root.
    void postOrderTraversal(TreeNode<T>* node) {
        if (node != nullptr) {
            postOrderTraversal(node->leftNode);
            postOrderTraversal(node->rightNode);
            cout << node->data << endl;
        }
    }

// Method to find max value in tree. Time Complexity: O(h), where h is the height of the tree    
    T findMax (TreeNode<T>* node) {
        if (node == nullptr)
            throw logic_error("Empty tree");

        while (node->rightNode != nullptr) {
            node = node->rightNode;
        }
        return node->data;
    }

// Method to find min value in tree. Time Complexity: O(h), where h is the height of the tree    
    T findMin (TreeNode<T>* node) {
        if (node == nullptr)
            throw logic_error("Empty tree");

        while (node->leftNode != nullptr) {
            node = node->leftNode;
        }
        return node->data;
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

    void preOrderTraversal() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrderTraversal(root);
        cout << endl;
    }

    void findMax() {
        cout << findMax(root) << endl;
    }

    void findMin() {
        cout << findMin(root) << endl;
    }
};


int main() {
    BST<int> bst1;
    bst1.insert(4);
    bst1.insert(5);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(3);
    bst1.insert(8);
    bst1.insert(7);
    bst1.inorderTraversal();
    bst1.preOrderTraversal();
    bst1.postOrderTraversal();
    bst1.findMax();
    bst1.findMin();
    return 0;
}
