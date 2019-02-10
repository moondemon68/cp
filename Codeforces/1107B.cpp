#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main () {
    int q;
    cin >> q;
    while (q--) {
        LL n,k;
        cin >> n >> k;
        cout << 9*(n-1)+k << endl;
    }
    return 0;
}