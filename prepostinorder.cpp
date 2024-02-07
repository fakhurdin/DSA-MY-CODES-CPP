#include <iostream>
#include <stack>
using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform iterative preorder traversal
void iterativePreorder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* currNode = nodeStack.top();
        cout << currNode->data << " ";
        nodeStack.pop();

        if (currNode->right != nullptr)
            nodeStack.push(currNode->right);

        if (currNode->left != nullptr)
            nodeStack.push(currNode->left);
    }
}

// Function to perform iterative inorder traversal
void iterativeInorder(Node* root) {
    stack<Node*> nodeStack;
    Node* currNode = root;

    while (currNode != nullptr || !nodeStack.empty()) {
        while (currNode != nullptr) {
            nodeStack.push(currNode);
            currNode = currNode->left;
        }

        currNode = nodeStack.top();
        nodeStack.pop();
        cout << currNode->data << " ";

        currNode = currNode->right;
    }
}

// Function to perform iterative postorder traversal
void iterativePostorder(Node* root) {
    stack<Node*> nodeStack;
    stack<int> resultStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* currNode = nodeStack.top();
        nodeStack.pop();
        resultStack.push(currNode->data);

        if (currNode->left != nullptr)
            nodeStack.push(currNode->left);

        if (currNode->right != nullptr)
            nodeStack.push(currNode->right);
    }

    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
    }
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    cout << "Preorder Traversal: ";
    iterativePreorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    iterativeInorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    iterativePostorder(root);
    cout << endl;

    return 0;
}

