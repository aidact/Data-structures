#include <iostream>
#include <ctime>

using namespace std;

int n, a[100100];
int L[100100], szl = 0;
int R[100100], szr = 0;

void quick_sort(int l, int r) {
    if (r - l < 2) return;
    int pos = rand() % (r - l) + l;
    int pivot = a[pos];
    szl = szr = 0;
    for (int i = l; i < r; i++) {
        if (i == pos) continue;
        if (a[i] <= pivot) L[szl++] = a[i];
        else R[szr++] = a[i];
    }
    for (int i = l; i < r; i++) {
        if (i - l < szl) a[i] = L[i - l];
        else if (i - l == szl) a[i] = pivot;
        else a[i] = R[i - l - szl - 1];
    }
    quick_sort(l, l + szl);
    quick_sort(l + szl + 1, r);
}

int main () {

    srand(time(NULL));

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    quick_sort(0, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}