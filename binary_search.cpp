// You're given non-decreasing array and value X
// Use binary search to answer if array contains X

#include <iostream>

using namespace std;

int n, a[100100];
int x;

int main () {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    // initialize initial ends of searching segment. r is inclusive
    int l = 0, r = n - 1;

    // do loop while we have non-empty segment, i.e. l <= r
    while (l <= r) {
        // choose middle element of segment
        int mid = (l + r) / 2;
        if (a[mid] == x) { // if we lucky then just print YES and finish program
            cout << "YES" << endl;
            return 0;
        }
        if (a[mid] < x) {
            // this case means that all elements before mid are also smaller than X
            // so that means that we need to go with right part of our segment
            // [l, r] must become [mid + 1, r], thats only one assigning
            l = mid + 1;
        }
        else {
            // this case means that all elements after mid are also greater than X
            // so that means that we need to go with left part of our segment
            // [l, r] must become [l, mid - 1], thats only one assigning
            r = mid - 1;
        }
    }

    // If our program reaches this line, then it means that there is no X in array
    cout << "NO" << endl;

    return 0;
}