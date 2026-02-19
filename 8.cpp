#include <iostream>
using namespace std;
#define SIZE 10

class OBST {
    int p[SIZE];
    int q[SIZE];
    int a[SIZE];
    int w[SIZE][SIZE];
    int c[SIZE][SIZE];
    int r[SIZE][SIZE];
    int n;

public:
    void get_data() {
        int i;
        cout << "\nOptimal Binary Search Tree\n";
        cout << "Enter the number of nodes: ";
        cin >> n;
        cout << "Enter the data nodes:\n";
        for (i = 1; i <= n; i++) {
            cout << "a[" << i << "]: ";
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cout << "p[" << i << "]: ";
            cin >> p[i];
        }
        for (i = 0; i <= n; i++) {
            cout << "q[" << i << "]: ";
            cin >> q[i];
        }
    }

    int Min_Value(int i, int j) {
        int m, k;
        int minimum = 32000;
        for (m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
            if ((c[i][m - 1] + c[m][j]) < minimum) {
                minimum = c[i][m - 1] + c[m][j];
                k = m;
            }
        }
        return k;
    }

    void build_OBST() {
        int i, j, k, m;
        for (i = 0; i < n; i++) {
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;
        for (m = 2; m <= n; m++) {
            for (i = 0; i <= n - m; i++) {
                j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
    }

    void build_tree() {
        int i, j, k;
        int queue[20], front = -1, rear = -1;
        cout << "\nRoot of OBST: " << r[0][n];
        cout << "\nCost of OBST: " << c[0][n];
        cout << "\n\nNODE\tLEFT\tRIGHT\n";
        queue[++rear] = 0;
        queue[++rear] = n;
        while (front != rear) {
            i = queue[++front];
            j = queue[++front];
            k = r[i][j];
            cout << k << "\t";
            if (r[i][k - 1] != 0) {
                cout << r[i][k - 1] << "\t";
                queue[++rear] = i;
                queue[++rear] = k - 1;
            } else {
                cout << "\t";
            }
            if (r[k][j] != 0) {
                cout << r[k][j];
                queue[++rear] = k;
                queue[++rear] = j;
            } else {
                cout << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    OBST obj;
    obj.get_data();
    obj.build_OBST();
    obj.build_tree();
    return 0;
}