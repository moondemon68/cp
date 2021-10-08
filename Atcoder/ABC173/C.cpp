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
    int n,m,k;
    cin >> n >> m >> k;
    char a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j] = s[j-1];
        }
    }
    int ans = 0;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<(1<<m);j++) {
            vector<int> s,t;
            int x = i;
            while (s.size() < n) {
                s.pb(x%2);
                x/=2;
            }
            x = j;
            while (t.size() < m) {
                t.pb(x%2);
                x/=2;
            }
            char b[n+5][m+5];
            for (int k=1;k<=n;k++) {
                for (int l=1;l<=m;l++) {
                    if (s[k-1] == 1 || t[l-1] == 1) b[k][l] = '.';
                    else b[k][l] = a[k][l];
                }
            }
            int cnt = 0;
            for (int k=1;k<=n;k++) {
                for (int l=1;l<=m;l++) {
                    if (b[k][l] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}