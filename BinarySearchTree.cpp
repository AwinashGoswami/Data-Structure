#include "BinarySearchTree.h"
#include <iostream>
#include <climits>
using namespace std;

// Constructor
BinarySearchTree::BinarySearchTree() : BinaryTree() {
    cout << "Binary Search Tree created" << endl;
}

// Helper function to insert a node
TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        cout << "Duplicate value " << value << " not inserted" << endl;
    }

    return node;
}

// Public insert method
void BinarySearchTree::insert(int value) {
    root = insert(root, value);
    cout << value << " inserted into BST" << endl;
}

// Helper function to find minimum value node
TreeNode* BinarySearchTree::findMin(TreeNode* node) const {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Public findMin method
int BinarySearchTree::findMin() const {
    TreeNode* minNode = findMin(root);
    if (minNode == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    cout << "Minimum value: " << minNode->data << endl;
    return minNode->data;
}

// Helper function to find maximum value node
TreeNode* BinarySearchTree::findMax(TreeNode* node) const {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// Public findMax method
int BinarySearchTree::findMax() const {
    TreeNode* maxNode = findMax(root);
    if (maxNode == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    cout << "Maximum value: " << maxNode->data << endl;
    return maxNode->data;
}

// Helper function to search in BST
TreeNode* BinarySearchTree::search(TreeNode* node, int value) const {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

// Public search method (efficient BST search)
bool BinarySearchTree::searchBST(int value) const {
    TreeNode* result = search(root, value);
    if (result != nullptr) {
        cout << value << " found in BST" << endl;
        return true;
    } else {
        cout << value << " not found in BST" << endl;
        return false;
    }
}

// Helper function to remove a node
TreeNode* BinarySearchTree::remove(TreeNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    // Search for the node to delete
    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        // Node found - handle deletion cases

        // Case 1: No child or only right child
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        // Case 2: Only left child
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        else {
            // Find inorder successor (minimum in right subtree)
            TreeNode* successor = findMin(node->right);
            // Copy successor's data to current node
            node->data = successor->data;
            // Delete the successor
            node->right = remove(node->right, successor->data);
        }
    }

    return node;
}

// Public remove method
void BinarySearchTree::remove(int value) {
    if (search(root, value) == nullptr) {
        cout << value << " not found in BST, cannot remove" << endl;
        return;
    }

    root = remove(root, value);
    cout << value << " removed from BST" << endl;
}

// Find successor (next larger element)
int BinarySearchTree::successor(int value) const {
    TreeNode* current = search(root, value);
    if (current == nullptr) {
        cout << value << " not found in tree" << endl;
        return -1;
    }

    // Case 1: Node has right subtree
    if (current->right != nullptr) {
        TreeNode* successor = findMin(current->right);
        cout << "Successor of " << value << " is " << successor->data << endl;
        return successor->data;
    }

    // Case 2: No right subtree - need to find ancestor
    TreeNode* ancestor = root;
    TreeNode* successor = nullptr;

    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    if (successor == nullptr) {
        cout << value << " has no successor (largest element)" << endl;
        return -1;
    }

    cout << "Successor of " << value << " is " << successor->data << endl;
    return successor->data;
}

// Find predecessor (next smaller element)
int BinarySearchTree::predecessor(int value) const {
    TreeNode* current = search(root, value);
    if (current == nullptr) {
        cout << value << " not found in tree" << endl;
        return -1;
    }

    // Case 1: Node has left subtree
    if (current->left != nullptr) {
        TreeNode* predecessor = findMax(current->left);
        cout << "Predecessor of " << value << " is " << predecessor->data << endl;
        return predecessor->data;
    }

    // Case 2: No left subtree - need to find ancestor
    TreeNode* ancestor = root;
    TreeNode* predecessor = nullptr;

    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    if (predecessor == nullptr) {
        cout << value << " has no predecessor (smallest element)" << endl;
        return -1;
    }

    cout << "Predecessor of " << value << " is " << predecessor->data << endl;
    return predecessor->data;
}

// Helper function to validate BST
bool BinarySearchTree::isValidBST(TreeNode* node, int min, int max) const {
    if (node == nullptr) {
        return true;
    }

    if (node->data < min || node->data > max) {
        return false;
    }

    return isValidBST(node->left, min, node->data - 1) &&
           isValidBST(node->right, node->data + 1, max);
}

// Public method to check if tree is valid BST
bool BinarySearchTree::isValidBST() const {
    bool valid = isValidBST(root, INT_MIN, INT_MAX);
    cout << "Is valid BST: " << (valid ? "Yes" : "No") << endl;
    return valid;
}
