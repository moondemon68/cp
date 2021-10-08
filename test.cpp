#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int a[MAXN + 5];

// helper function to merge
long long merge(int low, int mid, int high) {
    int temp[MAXN + 5];
    int i, j, k;
    long long inv_count;
    i = low;
    j = mid;
    k = low;

    inv_count = 0;

    while ((i <= mid - 1) && (j <= high)) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    for (i = low; i <= high; i++) {
        a[i] = temp[i];
    }

    return inv_count;
}

// returns number of inversions and merge sorts the array
long long mergesort(int l, int h) {
    int mid;
    long long inv_count;
    inv_count = 0;
    if (h > l) {
        mid = (l + h) / 2;
        inv_count = mergesort(l, mid);
        inv_count += mergesort(mid+1, h);
        inv_count += merge(l, mid+1, h);
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << mergesort(1, n) << endl;
    return 0;
}