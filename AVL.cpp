#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

public:
    node() : left(NULL), right(NULL) {}
    node(int data) : node() { this->data = data; }
};

class AVL {
public:
    node* root;
public:
    AVL() {}

    int height(node* root) {
        if (!root) { return 0; }

        int l = height(root->left);
        int r = height(root->right);

        return (max(l, r) + 1);
    }

    int GetBf(node* root) {
        if (!root) { return 0; }

        return (height(root->left) - height(root->right));
    }

    node* LEFTROTATE(node*& root) {
        node* temp = root->right;
        root->right = temp->left;
        temp->left = root;

        return temp;
    }

    node* RIGHTROTATE(node*& root) {
        node* temp = root->left;
        root->left = temp->right;
        temp->right = root;

        return temp;
    }

    void Insert(node*& root, int data) {
        if (!root) {
            root = new node(data);
            return;
        }

        if (root->data > data) {
            Insert(root->left, data);
        }
        else if (root->data < data) {
            Insert(root->right, data);
        }

        int BalanceFactor = GetBf(root);

        if (BalanceFactor < -1 && data > root->right->data) {
            root = LEFTROTATE(root);
        }
        if (BalanceFactor > 1 && data < root->left->data) {
            root = RIGHTROTATE(root);
        }
        if (BalanceFactor > 1 && data > root->left->data) {
            root->left = LEFTROTATE(root->left);
            root = RIGHTROTATE(root);
        }
        if (BalanceFactor < -1 && data < root->right->data) {
            root->right = RIGHTROTATE(root->right);
            root = LEFTROTATE(root);
        }
    }

    node* Getmin(node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    void Delete(node*& root, int data) {
        if (!root) {
            return;
        }

        if (root->data > data) {
            Delete(root->left, data);
        }
        else if (root->data < data) {
            Delete(root->right, data);
        }
        else {
            // Data Found -> to be deleted
            if (root->left == NULL && root->right == NULL) {
                delete (root);
                root = NULL;
            }
            else if (root->left == NULL) {
                node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) {
                node* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                node* minIndex = Getmin(root->right);
                root->data = minIndex->data;
                Delete(root->right, minIndex->data);
            }

            int BalanceFactor = GetBf(root);

            if (BalanceFactor < -1 && GetBf(root->right) <= 0) {
                root = LEFTROTATE(root);
            }
            if (BalanceFactor > 1 && GetBf(root->left) >= 0) {
                root = RIGHTROTATE(root);
            }
            if (BalanceFactor > 1 && GetBf(root->left) < 0) {
                root->left = LEFTROTATE(root->left);
                root = RIGHTROTATE(root);
            }
            if (BalanceFactor < -1 && GetBf(root->right) > 0) {
                root->right = RIGHTROTATE(root->right);
                root = LEFTROTATE(root);
            }
        }
    }
    void Update(node*& root, int data) {
        Delete(root, data);
        int newdata;
        cout << "Enter New Data :   "; cin >> newdata;
        Insert(root, newdata);
    }
};
    void PrintTree(node* root) {
        if (!root) { return; }

        PrintTree(root->left);
        cout << root->data << "   ";
        PrintTree(root->right);
    }

    int main() {
        AVL t;
        t.Insert(t.root, 11);
        t.Insert(t.root, 12);
        t.Insert(t.root, 13);

        cout << "Original Tree: ";
        PrintTree(t.root);
        cout << endl;

        t.Delete(t.root, 12);

        cout << "Tree after deleting: ";
        PrintTree(t.root);
        cout << endl;
        cout << "Tree after Updating : ";
        t.Update(t.root, 11);
        PrintTree(t.root);

        return 0;
    }
