#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findSuccessor(TreeNode* root, int target) {
    TreeNode* curr = root;
    TreeNode* successor = NULL;

    while (curr) {
        if (curr->val > target) {
            successor = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return successor;
}

int main() {
    // Creating a sample Binary Search Tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    int target = 4;

    TreeNode* successor = findSuccessor(root, target);

    if (successor) {
        cout << "Successor of " << target << " is: " << successor->val << endl;
    } else {
        cout << "No successor found for " << target << endl;
    }

    // Clean up memory (deallocation of nodes)
    // For brevity, skipping the deletion of nodes in this example.

    return 0;
}

