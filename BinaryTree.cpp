#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Constructor
BinaryTree::BinaryTree() {
    root = nullptr;
    cout << "Binary Tree created" << endl;
}

// Copy constructor
BinaryTree::BinaryTree(const BinaryTree& other) {
    root = copyTree(other.root);
    cout << "Binary Tree copied" << endl;
}

// Helper function to copy tree
TreeNode* BinaryTree::copyTree(TreeNode* sourceNode) {
    if (sourceNode == nullptr) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(sourceNode->data);
    newNode->left = copyTree(sourceNode->left);
    newNode->right = copyTree(sourceNode->right);

    return newNode;
}

// Destructor
BinaryTree::~BinaryTree() {
    clear();
    cout << "Binary Tree destroyed" << endl;
}

// Helper function to destroy tree
void BinaryTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Check if tree is empty
bool BinaryTree::isEmpty() const {
    return root == nullptr;
}

// Clear the tree
void BinaryTree::clear() {
    destroyTree(root);
    root = nullptr;
    cout << "Tree cleared" << endl;
}

// Preorder traversal (Root -> Left -> Right)
void BinaryTree::preorderTraversal(TreeNode* node) const {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void BinaryTree::preorder() const {
    cout << "Preorder traversal (Recursive): ";
    preorderTraversal(root);
    cout << endl;
}

// Inorder traversal (Left -> Root -> Right)
void BinaryTree::inorderTraversal(TreeNode* node) const {
    if (node == nullptr) {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void BinaryTree::inorder() const {
    cout << "Inorder traversal (Recursive): ";
    inorderTraversal(root);
    cout << endl;
}

// Postorder traversal (Left -> Right -> Root)
void BinaryTree::postorderTraversal(TreeNode* node) const {
    if (node == nullptr) {
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

void BinaryTree::postorder() const {
    cout << "Postorder traversal (Recursive): ";
    postorderTraversal(root);
    cout << endl;
}

// Level order traversal (Breadth-first)
void BinaryTree::levelOrder() const {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    cout << "Level order traversal: ";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Inorder traversal (Iterative)
void BinaryTree::inorderIterative() const {
    cout << "Inorder traversal (Iterative): ";

    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current is null, pop from stack
        current = s.top();
        s.pop();

        cout << current->data << " ";

        // Move to right subtree
        current = current->right;
    }
    cout << endl;
}

// Preorder traversal (Iterative)
void BinaryTree::preorderIterative() const {
    cout << "Preorder traversal (Iterative): ";

    if (root == nullptr) {
        cout << endl;
        return;
    }

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push right first so left is processed first (LIFO)
        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
    cout << endl;
}

// Postorder traversal (Iterative) - Using two stacks
void BinaryTree::postorderIterative() const {
    cout << "Postorder traversal (Iterative): ";

    if (root == nullptr) {
        cout << endl;
        return;
    }

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr) {
            s1.push(current->left);
        }
        if (current->right != nullptr) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

// Helper function to print a specific level
void BinaryTree::printGivenLevel(TreeNode* node, int level) const {
    if (node == nullptr) {
        return;
    }
    if (level == 1) {
        cout << node->data << " ";
    } else if (level > 1) {
        printGivenLevel(node->left, level - 1);
        printGivenLevel(node->right, level - 1);
    }
}

// Calculate height of tree
int BinaryTree::height(TreeNode* node) const {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return max(leftHeight, rightHeight) + 1;
}

int BinaryTree::height() const {
    int h = height(root);
    cout << "Tree height: " << h << endl;
    return h;
}

// Count number of nodes
int BinaryTree::countNodes(TreeNode* node) const {
    if (node == nullptr) {
        return 0;
    }

    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BinaryTree::numberOfNodes() const {
    int count = countNodes(root);
    cout << "Number of nodes: " << count << endl;
    return count;
}

// Count number of leaves
int BinaryTree::countLeaves(TreeNode* node) const {
    if (node == nullptr) {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }

    return countLeaves(node->left) + countLeaves(node->right);
}

int BinaryTree::numberOfLeaves() const {
    int count = countLeaves(root);
    cout << "Number of leaves: " << count << endl;
    return count;
}

// Count number of full nodes (nodes with two children)
int BinaryTree::numberOfFullNodes() const {
    if (root == nullptr) {
        cout << "Number of full nodes: 0" << endl;
        return 0;
    }

    int count = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current->left != nullptr && current->right != nullptr) {
            count++;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    cout << "Number of full nodes: " << count << endl;
    return count;
}

// Search for a value (linear search for general binary tree)
bool BinaryTree::search(int value) const {
    if (root == nullptr) {
        return false;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current->data == value) {
            cout << value << " found in the tree" << endl;
            return true;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    cout << value << " not found in the tree" << endl;
    return false;
}

// Assignment operator
BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {
        clear();
        root = copyTree(other.root);
    }
    return *this;
}
