#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform an inorder traversal of the BST
void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr) return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

// Function to convert the sorted elements into a Max Heap
TreeNode* buildMaxHeap(vector<int>& inorder) {
    if (inorder.empty()) return nullptr;

    queue<TreeNode*> nodes;
    TreeNode* root = new TreeNode(inorder[0]);
    nodes.push(root);

    for (int i = 1; i < inorder.size(); ++i) {
        TreeNode* newNode = new TreeNode(inorder[i]);
        TreeNode* parent = nodes.front();
        nodes.pop();

        if (parent->left == nullptr) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            nodes.pop(); // Remove the parent as both children are now assigned
        }

        nodes.push(newNode);
        nodes.push(parent);
    }

    return root;
}

// Function to perform a postorder traversal of the Max Heap
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

// Function to convert BST to Special Max Heap
void convertBSTToMaxHeap(TreeNode* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    TreeNode* maxHeapRoot = buildMaxHeap(inorder);
    postorderTraversal(maxHeapRoot);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "Output: ";
    convertBSTToMaxHeap(root);
    cout << endl;

    return 0;
}

