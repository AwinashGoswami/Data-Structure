#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "TreeNode.h"
#include <queue>
#include <stack>

class BinaryTree {
protected:
    TreeNode* root;

    // Helper functions for recursive operations
    void destroyTree(TreeNode* node);
    void preorderTraversal(TreeNode* node) const;
    void inorderTraversal(TreeNode* node) const;
    void postorderTraversal(TreeNode* node) const;
    int height(TreeNode* node) const;
    int countNodes(TreeNode* node) const;
    int countLeaves(TreeNode* node) const;
    void printGivenLevel(TreeNode* node, int level) const;
    TreeNode* copyTree(TreeNode* sourceNode);

public:
    // Constructor and Destructor
    BinaryTree();
    BinaryTree(const BinaryTree& other);  // Copy constructor
    ~BinaryTree();

    // Basic Operations
    bool isEmpty() const;
    void clear();

    // Traversal Methods (Recursive)
    void preorder() const;
    void inorder() const;
    void postorder() const;

    // Traversal Methods (Iterative)
    void levelOrder() const;
    void inorderIterative() const;
    void preorderIterative() const;
    void postorderIterative() const;

    // Tree Properties
    int height() const;
    int numberOfNodes() const;
    int numberOfLeaves() const;
    int numberOfFullNodes() const;

    // Search
    bool search(int value) const;

    // Assignment operator
    BinaryTree& operator=(const BinaryTree& other);
};


#endif // BINARYTREE_H_INCLUDED
