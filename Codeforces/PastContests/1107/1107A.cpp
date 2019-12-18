#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main () {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n==2&&s[0]>=s[1]) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " ";
            for (int i=1;i<s.size();i++) cout << s[i];
            cout << endl;
        }
    }
    return 0;
}