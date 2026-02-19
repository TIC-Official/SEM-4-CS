#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct avlnode {
    string key, mean;
    avlnode *left, *right;
    int height;
    avlnode(string k, string m) {
        key = k; mean = m;
        left = right = NULL;
        height = 1;
    }
};

class dictionary {
public:
    avlnode *root;
    dictionary() { root = NULL; }

    int height(avlnode *n) { return n ? n->height : 0; }
    int getBalance(avlnode *n) { return n ? height(n->left) - height(n->right) : 0; }

    avlnode* rightRotate(avlnode *y) {
        avlnode *x = y->left;
        avlnode *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    avlnode* leftRotate(avlnode *x) {
        avlnode *y = x->right;
        avlnode *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    avlnode* insert(avlnode* node, string key, string mean) {
        if (!node) return new avlnode(key, mean);
        if (key < node->key) node->left = insert(node->left, key, mean);
        else if (key > node->key) node->right = insert(node->right, key, mean);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) return rightRotate(node);
        if (balance < -1 && key > node->right->key) return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inorder(avlnode *root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " : " << root->mean << endl;
            inorder(root->right);
        }
    }
};

int main() {
    dictionary d;
    int ch;
    string k, m;
    while (true) {
        cout << "\n1.Insert 2.Display 3.Exit: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter word and meaning: ";
            cin >> k >> m;
            d.root = d.insert(d.root, k, m);
        } else if (ch == 2) d.inorder(d.root);
        else break;
    }
    return 0;
}