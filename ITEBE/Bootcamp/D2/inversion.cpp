#include <bits/stdc++.h>

using namespace std;

int a[100005];

int merge(int l, int m, int r) {
    int L[100005], R[100005];
    int nl = m-l+1, nr = r-m;   // jumlah elemen pada L dan R
    for (int i=1;i<=nl;i++) L[i] = a[l+i-1];    // L mengandung a[l] sampai a[m]
    for (int i=1;i<=nr;i++) R[i] = a[m+i];      // R mengandung a[m+1] sampai a[r]
    int pl = 1, pr = 1, p = l;  // pointers (penunjuk indeks)
    int cnt = 0;    // menyimpan jumlah inversi dari array yang akan disort
    // sorting
    while (pl <= nl && pr <= nr) {
        if (L[pl] > R[pr]) {
            a[p]=R[pr];
            pr++;
            cnt += nl - pl + 1; // hayo kenapa
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
    return cnt;
}

int mergeSort(int l, int r) {
    int cnt = 0;
    if (l < r) {    // ketika l == r, tidak di merge lagi
        int m = (l+r) / 2;
        cnt += mergeSort(l, m);    // mensort half pertama, menambahkan jumlah inversi
        cnt += mergeSort(m+1, r);  // mensort half kedua, menambahkan jumlah inversi
        cnt += merge(l, m, r);     // merge half pertama dan kedua
    }
    return cnt;
}

int main () {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int cnt = mergeSort(1, n);
    cout << cnt << endl;
    return 0;
}