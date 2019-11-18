#include <bits/stdc++.h>

using namespace std;

int a[100005];

void merge(int l, int m, int r) {
    int L[100005], R[100005];
    int nl = m-l+1, nr = r-m;   // jumlah elemen pada L dan R
    for (int i=1;i<=nl;i++) L[i] = a[l+i-1];    // L mengandung a[l] sampai a[m]
    for (int i=1;i<=nr;i++) R[i] = a[m+i];      // R mengandung a[m+1] sampai a[r]
    int pl = 1, pr = 1, p = l;  // pointers (penunjuk indeks)
    // sorting
    while (pl <= nl && pr <= nr) {
        if (L[pl] >= R[pr]) {
            a[p]=R[pr];
            pr++;
        } else {
            a[p]=L[pl];
            pl++;
        }
        p++;
    }
    // jika pr sudah sampai ujung tetapi pl belum
    while (pl <= nl) {
        a[p] = L[pl];
        pl++;
        p++;
    }
    // jika pl sudah sampai ujung tetapi pr belum
    while (pr <= nr) {
        a[p] = R[pr];
        pr++;
        p++;
    }
}

void mergeSort(int l, int r) {
    if (l < r) {    // ketika l == r, tidak di merge lagi
        int m = (l+r) / 2;
        mergeSort(l, m);    // mensort half pertama
        mergeSort(m+1, r);  // mensort half kedua
        merge(l, m, r);     // merge half pertama dan kedua
    }
}

int main () {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    mergeSort(1, n);
    for (int i=1;i<=n;i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}