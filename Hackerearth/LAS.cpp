#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int t(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k <= n/2) {
        return 2*t(n/2, k) - 1;
    } else return 2*t((n-1)/2, k-1-n/2);
}

int main () {
    int n,k;
    cin >> n >> k;
    if (n>1 && k==1) cout << "No" << endl;
    else if (n==1 && k==1) cout << "Yes" << endl << 1 << endl;
    else {
        cout << "Yes" << endl;
        vector<int> a;
        if (k == 2) {
            for (int i=0;i<n;i++) a.pb(t(n, i));
            for (int i=0;i<n;i++) cout << a[i] << " ";
        } else if ((n-k)%2==0) {
            for (int i=0;i<=n-k;i++) a.pb(t(n-k, i));
            for (int i=0;i<=n-k;i++) cout << a[i] << " ";
            for (int i=n-k+2;i<=n;i++) cout << i << " ";
        } else {
            for (int i=0;i<=n-k;i++) a.pb(t(n-k, i));
            for (int i=n;i>=n-k+2;i--) cout << i <<  " ";
            for (int i=0;i<=n-k;i++) cout << a[i] << " ";
        }

    }
    return 0;
}
