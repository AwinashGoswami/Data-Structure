#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree {
private:
    // Helper functions for BST operations
    TreeNode* insert(TreeNode* node, int value);
    TreeNode* remove(TreeNode* node, int value);
    TreeNode* findMin(TreeNode* node) const;
    TreeNode* findMax(TreeNode* node) const;
    TreeNode* search(TreeNode* node, int value) const;

public:
    // Constructor
    BinarySearchTree();

    // BST Specific Operations
    void insert(int value);
    void remove(int value);
    int findMin() const;
    int findMax() const;
    bool searchBST(int value) const;  // Override for BST efficient search

    // Additional BST Operations
    int successor(int value) const;    // Find next larger element
    int predecessor(int value) const;  // Find next smaller element
    bool isValidBST() const;           // Check if tree is valid BST

private:
    // Helper for validation
    bool isValidBST(TreeNode* node, int min, int max) const;
};

#endif // BINARYSEARCHTREE_H_INCLUDED
