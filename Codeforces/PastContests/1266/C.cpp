#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;
    
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    if (r == 1) {
        if (c == 1) {
            cout << 0 << endl;
            return 0;
        }
        for (int i=1;i<=c;i++) {
            if (i == 1) cout << 2 << " ";
            else cout << 1+i << " ";
        }
        return 0;
    }
    if (c == 1) {
        for (int i=1;i<=r;i++) {
            if (i == 1) cout << 2 << endl;
            else cout << 1+i << endl;
        }
        return 0;
    }
    bool sw = 0;
    if (r < c) {
        swap(r,c);
        sw = 1;
    }
    int a[r+5][c+5];
    int maxi = 0;
    for (int i=1;i<=c;i++) {
        a[1][i] = 2*i;
        maxi = max(maxi, 2*i);
    }
    for (int i=1;i<=c;i++) {
        a[i][1] = 2*i-1;
        maxi = max(maxi, 2*i-1);
    }
    for (int i=c+1;i<=r;i++) a[i][1]=maxi-c+i;
    a[1][1]=2;
    for (int i=2;i<=r;i++) {
        for (int j=2;j<=c;j++) {
            a[i][j] = a[i][1] * a[1][j];
        }
    }
    if (!sw) {
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for (int i=1;i<=c;i++) {
            for (int j=1;j<=r;j++) {
                cout << a[j][i] << " ";
            }
            cout << endl;
        }
    }
    // set<int> s;
    // int ans=0;
    // for (int i=1;i<=r;i++) {
    //     int g = a[i][1];
    //     for (int j=1;j<=c;j++) g = __gcd(a[i][j], g);
    //     ans = max(g, ans);
    // }
    // for (int i=1;i<=c;i++) {
    //     int g = a[1][i];
    //     for (int j=1;j<=r;j++) g = __gcd(a[j][i], g);
    //     ans = max(g, ans);
    // }
    // cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}