#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0};
int visited[50] = {0};

void dfs(int s, int n, string arr[]) {
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
        if (adj_mat[s][i] && !visited[i]) dfs(i, n, arr);
}

void bfs(int s, int n, string arr[]) {
    bool v_bfs[50] = {false};
    queue<int> q;
    cout << arr[s] << " ";
    v_bfs[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            if (adj_mat[v][i] && !v_bfs[i]) {
                cout << arr[i] << " ";
                v_bfs[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, u;
    cout << "Enter no. of cities: "; cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++) cin >> cities[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Dist " << cities[i] << "-" << cities[j] << ": ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << "Start vertex index: "; cin >> u;
    cout << "DFS: "; dfs(u, n, cities);
    cout << "\nBFS: "; bfs(u, n, cities);
    return 0;
}