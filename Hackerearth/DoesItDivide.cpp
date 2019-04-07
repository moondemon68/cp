#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    for (int i=2;i*i<=x;i++) {
        if (x%i==0) return 0;
    }
    return 1;
}

int main () {
    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;
        if (x%2) cout << "YES" << endl;
        else {
            if (!isPrime(x+1)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}