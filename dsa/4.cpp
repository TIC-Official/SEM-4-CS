#include <iostream>
using namespace std;

class bstnode {
    int data;
    bstnode *right, *left;
public:
    bstnode* create(int data) {
        bstnode *temp = new bstnode();
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    bstnode* insert(bstnode *root, int data) {
        if (root == NULL) return create(data);
        if (data < root->data) root->left = insert(root->left, data);
        else if (data > root->data) root->right = insert(root->right, data);
        return root;
    }
    bool search(bstnode *root, int data) {
        if (root == NULL) return false;
        if (root->data == data) return true;
        return (data < root->data) ? search(root->left, data) : search(root->right, data);
    }
    void inorder(bstnode *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    int height(bstnode *root) {
        if (root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void mirror(bstnode *root) {
        if (root == NULL) return;
        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
};

int main() {
    bstnode *root = NULL; bstnode b; int ch, val;
    while(true) {
        cout << "\n1.Insert 2.Inorder 3.Mirror 4.Height 5.Exit: ";
        cin >> ch;
        if(ch==1) { cin >> val; root = b.insert(root, val); }
        else if(ch==2) b.inorder(root);
        else if(ch==3) b.mirror(root);
        else if(ch==4) cout << b.height(root);
        else exit(0);
    }
}