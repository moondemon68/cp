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
    int r, c, q;
    cin >> r >> c >> q;
    int a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j] = s[j-1];
        }
    }
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (q--) {
        string s;
        cin >> s;
        bool done = 0;
        for (int i=1;i<=r;i++) {
            if (done) break;
            for (int j=1;j<=c;j++) {
                if (done) break;
                for (int k=0;k<8;k++) {
                    bool y = 1;
                    for (int l=0;l<s.size();l++) {
                        if (a[i + dx[k] * l][j + dy[k] * l] != s[l]) {
                            y = 0;
                            break;
                        }
                    }
                    if (y) {
                        cout << i-1 << " " << j-1 << " " << i-1 + dx[k] * (s.size()-1) << " " << j-1 + dy[k] * (s.size()-1) << endl;
                        done = 1;
                        break;
                    }
                }
            }
        }
        if (!done) cout << -1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}