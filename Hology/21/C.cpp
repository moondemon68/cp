#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL merge(LL a[], LL tmp[], LL l, LL m, LL r) {
    LL i, j, k;
    LL inv_count = 0;
    i = l;
    j = m;
    k = l;
    while ((i <= m - 1) && (j <= r)) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            inv_count += (m - i);
        }
    }
    while (i <= m - 1) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (i = l; i <= r; i++) {
        a[i] = tmp[i];
    }
    return inv_count;
}

LL _mergeSort(LL a[], LL tmp[], LL l, LL r) {
    LL mid, inv_count = 0;
    if (r > l) {
        mid = (l + r) / 2;
        inv_count += _mergeSort(a, tmp, l, mid);
        inv_count += _mergeSort(a, tmp, mid + 1, r);
        inv_count += merge(a, tmp, l, mid + 1, r); 
    }
    return inv_count;
}

LL mergeSort(LL a[], LL n) {
    LL tmp[n];
    return _mergeSort(a, tmp, 0, n - 1);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n*n];
    LL b[n*n];
    LL x = 0;
    LL p = -1;
    for (LL i=0;i<n*n;i++) {
        cin >> a[i];
        if (a[i] == 0) x = i;
        else p++;
        b[p] = a[i];
    }
    x = n - x / n;
    LL inv =  mergeSort(b, n*n-1);
    // cout << x << " " << inv << endl;
    if ((n % 2 == 1 && inv % 2 == 0) || (n % 2 == 0 && x % 2 == 0 && inv % 2 == 1) || (n % 2 == 0 && x % 2 == 1 && inv % 2 == 0)) cout << "YA" << endl;
    else cout << "TIDAK" << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}