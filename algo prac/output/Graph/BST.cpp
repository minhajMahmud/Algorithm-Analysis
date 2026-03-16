#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node in the BST
Node* insert(Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == nullptr) {
        return new Node(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    // Base cases: root is null or value is present at the root
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }

    // If the value is smaller than the root's data, search in the left subtree
    if (value < root->data) {
        return search(root->left, value);
    } else { // If the value is larger, search in the right subtree
        return search(root->right, value);
    }
}

// In-order traversal of the BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);  // Visit left subtree
        cout << root->data << " ";  // Print the root
        inorder(root->right);  // Visit right subtree
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    // Ask the user for the number of activities/values to insert
    cout << "Enter the number of values to insert into the BST: ";
    cin >> n;

    // Input the values to insert into the BST
    cout << "Enter the values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);  // Insert each value into the BST
    }

    // Perform in-order traversal to print the tree's values in sorted order
    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl;

    // Ask the user for a value to search in the BST
    cout << "Enter a value to search in the BST: ";
    cin >> value;

    // Call the search function
    if (search(root, value)) {
        cout << "Value " << value << " found in the BST." << endl;
    } else {
        cout << "Value " << value << " not found in the BST." << endl;
    }

    return 0;
}
