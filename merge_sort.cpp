#include <iostream>

using namespace std;

int n, a[100100];
int tmp[100100];

void merge_sort(int l, int r) {
    if (r - l < 2) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid, r);
    int i = l, j = mid;
    int sz = l;
    while (i < mid && j < r) {
        if (a[i] < a[j]) {
            tmp[sz++] = a[i++];
        } else {
            tmp[sz++] = a[j++];
        }
    }
    while (i < mid) {
        tmp[sz++] = a[i++];
    }
    while (j < r) {
        tmp[sz++] = a[j++];
    }
    for (int t = l; t < r; t++) a[t] = tmp[t];
}

int main () {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    merge_sort(0, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}