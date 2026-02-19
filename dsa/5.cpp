#include <iostream>
#include <string.h>

using namespace std;

struct node {
    char data;
    node *left, *right;
};

class stack1 {
    node *data[30];
    int top;
public:
    stack1() { top = -1; }
    int empty() { return (top == -1); }
    void push(node *p) { data[++top] = p; }
    node *pop() { return data[top--]; }
};

class tree {
public:
    node *root;
    tree() { root = NULL; }
    void expression(char prefix[]) {
        stack1 s;
        int len = strlen(prefix);
        for (int i = len - 1; i >= 0; i--) {
            node *temp = new node;
            temp->data = prefix[i];
            temp->left = temp->right = NULL;
            if (isalpha(prefix[i])) {
                s.push(temp);
            } else {
                temp->left = s.pop();
                temp->right = s.pop();
                s.push(temp);
            }
        }
        root = s.pop();
    }
    void postorder(node *p) {
        if (p) {
            postorder(p->left);
            postorder(p->right);
            cout << p->data;
        }
    }
};

int main() {
    char expr[20];
    tree t;
    cout << "Enter prefix expression: ";
    cin >> expr;
    t.expression(expr);
    cout << "Postorder Traversal: ";
    t.postorder(t.root);
    return 0;
}