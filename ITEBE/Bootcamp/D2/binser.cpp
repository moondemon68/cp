#include <bits/stdc++.h>

using namespace std;

int main () {
    int n,q;
    cin >> n >> q;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);   // array harus terurut
    while (q--) {
        int x;
        cin >> x;
        int l = 1, h = n;   // batas bawah dan batas atas
        bool ada = 0;
        while (l<=h) {
            int m = (l + h) / 2; // tembak tengah
            if (x > a[m]) {
                l = m+1;    // buang elemen di kiri m (menaikkan batas bawah)
            } else if (x < a[m]) {
                h = m-1;    // buang elemen di kanan m (menurunkan batas atas)
            } else { // x == a[m]
                ada = 1;    // udah ketemu, keluar aja dari loopnya
                break;
            }
        }
        if (ada) cout << "Ya" << endl; else cout << "Tidak" << endl;
    }
    return 0;
}