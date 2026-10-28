#include <iostream>
#include <stdexcept>

// Node representation for Binary Search Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Inserts a new value into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Duplicate values are ignored in this implementation
    return root;
}

// Searches for a value in the BST
bool search(TreeNode* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// In-order traversal: Left -> Root -> Right (produces sorted order)
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Pre-order traversal: Root -> Left -> Right
void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal: Left -> Right -> Root
void postorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

// Finds minimum value in the BST
int findMin(TreeNode* root) {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Finds maximum value in the BST
int findMax(TreeNode* root) {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

// Frees all allocated memory in the tree (Post-order deletion)
void destroyTree(TreeNode* root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int main() {
    TreeNode* root = nullptr;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    std::cout << "--- Binary Search Tree (BST) in C++ ---\n\n";
    std::cout << "Inserting values: ";
    for (int val : values) {
        std::cout << val << " ";
        root = insert(root, val);
    }
    std::cout << "\n\n";

    std::cout << "In-order Traversal (Sorted): ";
    inorderTraversal(root);
    std::cout << "\n";

    std::cout << "Pre-order Traversal:         ";
    preorderTraversal(root);
    std::cout << "\n";

    std::cout << "Post-order Traversal:        ";
    postorderTraversal(root);
    std::cout << "\n\n";

    // Search tests
    int key1 = 40, key2 = 95;
    std::cout << "Search " << key1 << ": " << (search(root, key1) ? "Found" : "Not Found") << "\n";
    std::cout << "Search " << key2 << ": " << (search(root, key2) ? "Found" : "Not Found") << "\n\n";

    // Min and Max
    std::cout << "Minimum value in BST: " << findMin(root) << "\n";
    std::cout << "Maximum value in BST: " << findMax(root) << "\n";

    // Cleanup memory
    destroyTree(root);
    root = nullptr;

    return 0;
}
