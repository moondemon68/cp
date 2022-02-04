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
    string t = "";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
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
    if (y) {
        ans++;
    }
    t = "";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            t += 'A';
        } else {
            t += 'B';
        }
    }
    y = 1;
    for (int j = 0; j < n; j++) {
        if (s[j] != '?' && s[j] != t[j]) {
            y = 0;
            break;
        }
    }
    if (y) {
        ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}