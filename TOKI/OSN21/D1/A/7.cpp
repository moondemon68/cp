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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int ans = 0;
    int c[3005];
    memset(c,0,sizeof(c));
    for (int i = 0; i < (1<<n); i++) {
        string t = "";
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                t += 'A';
            } else {
                t += 'B';
            }
        }
        bool y = 1;
        for (int j = 0; j < n; j++) {
            if (s[j] != '?' && s[j] != t[j]) {
                y = 0;
                break;
            }
        }
        if (!y) continue;
        t += '*';
        int cnt = 0, cur = 1;
        for (int j = 1; j <= n; j++) {
            if (t[j] == t[j-1]) {
                cur++;
            } else {
                cnt += max(cur - m + 1, 0);
                cur = 1;
            }
        }
        if (cnt == k) {
            ans++;
        }
        // cout << t << " " << cnt << endl;
        c[cnt]++;
    }
    cout << ans << endl;
    for (int i = 0; i <= n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
3 1
0 0 0 8
3 2
2 4 2 0
3 3
6 2 0

5 1
0 0 0 0 0 32
5 2
2 8 12 8 2 0
5 3
16 10 4 2 0 0
5 4
26 4 2 0 0 0
5 5
30 2 0 0 0 0
*/