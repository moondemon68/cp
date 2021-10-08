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
const int N = 1000000;
int nextt[2][N+5], prevv[2][N+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(nextt,0,sizeof(nextt));
    memset(prevv,0,sizeof(prevv));
    int ncur[2];
    ncur[0] = n;
    ncur[1] = n;
    for (int i=n-1;i>=0;i--) {
        if (s[i] != '?') {
            ncur[s[i]-'0'] = i;
        }
        nextt[0][i] = ncur[0];
        nextt[1][i] = ncur[1];
    }

    int pcur[2];
    pcur[0] = -1;
    pcur[1] = -1;
    for (int i=0;i<=n;i++) {
        if (s[i] != '?') {
            pcur[s[i]-'0'] = i;
        }
        prevv[0][i] = pcur[0];
        prevv[1][i] = pcur[1];
    }

    for (int i=1;i<=n;i++) {
        int p = 0, ans = 0;
        while (p + i <= n) {
            if (nextt[0][p] >= p + i || nextt[1][p] >= p + i) {
                ans++;
                p += i;
            } else {
                p = min(prevv[0][p+i], prevv[1][p+i]) + 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}