#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,p,q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    vector<string> ans;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            if (i*p+j*q==n) {
                cout << i+j << endl;
                for (int k=0;k<i;k++) {
                    for (int l=0;l<p;l++) {
                        cout << s[k*p+l];
                    }
                    cout << endl;
                }
                for (int k=0;k<j;k++) {
                    for (int l=0;l<q;l++) {
                        cout << s[i*p+k*q+l];
                    }
                    cout << endl;
                }
                return 0;
            }
        }
        
    }
    cout << -1 << endl;
    return 0;
}