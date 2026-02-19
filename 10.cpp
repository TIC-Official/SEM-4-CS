#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void MinHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void MaxHeapSort(int a[], int n) {
    int i, temp;
    for (i = n; i >= 2; i--) {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MaxHeapify(a, 1, i - 1);
    }
}

void MinHeapSort(int a[], int n) {
    int i, temp;
    for (i = n; i >= 2; i--) {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MinHeapify(a, 1, i - 1);
    }
}

void Build_MaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}

void Build_MinHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--)
        MinHeapify(a, i, n);
}

int main() {
    int n, i;
    cout << "\nEnter number of subjects: ";
    cin >> n;
    int arr[n + 1];

    for (i = 1; i <= n; i++) {
        cout << "Enter marks " << i << ": ";
        cin >> arr[i];
    }

    Build_MaxHeap(arr, n);
    MaxHeapSort(arr, n);
    int min_val = arr[1];
    
    cout << "\nSorted Data (ASCENDING): ";
    for (i = 1; i <= n; i++)
        cout << arr[i] << " ";

    Build_MinHeap(arr, n);
    MinHeapSort(arr, n);
    int max_val = arr[1];

    cout << "\nSorted Data (DESCENDING): ";
    for (i = 1; i <= n; i++)
        cout << arr[i] << " ";

    cout << "\n\nMaximum Marks: " << max_val;
    cout << "\nMinimum Marks: " << min_val << endl;

    return 0;
}