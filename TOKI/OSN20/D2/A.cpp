#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
using namespace std;

const int limit = 20;

int can[1<<limit];
int t[1<<limit];
int dp[2][1<<limit];
vector<int> adj[1<<limit];

vector<int> cari;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;


    for (int j=0;j<(1<<k);j++) {
        if (__builtin_popcount(j) == 4) {
            cari.pb(j);
        }
    }

    // int cnt = 0;
    for (int j : cari) {
        adj[j].pb(j);
        // cnt++;
        for (int p=0;p<k;p++) {
            for (int q=p+1;q<k;q++) {
                if (((j&(1<<p)) > 0 && (j&(1<<q)) == 0)) {
                    int x = j;
                    x ^= (1 << p);
                    x ^= (1 << q);
                    adj[j].pb(x);
                    x ^= (1 << p);
                    x ^= (1 << q);
                    // cnt++;
                }
                if (((j&(1<<p)) == 0 && (j&(1<<q)) > 0)) {
                    int x = j;
                    x ^= (1 << p);
                    x ^= (1 << q);
                    adj[j].pb(x);
                    x ^= (1 << p);
                    x ^= (1 << q);
                    // cnt++;
                }
            }
        }
    }
    // cerr << cnt << endl;

    int a[k+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=4;i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int skill = 0;
    for (int i=1;i<=k;i++) {
        skill += a[i];
        skill *= 2;
    }
    skill /= 2;


    int m[k+5];
    memset (m,0,sizeof(m));
    for (int i=1;i<=k;i++) {
        string s;
        cin >> s;
        int cur = 0;
        for (int j=1;j<=k;j++) {
            cur += s[j-1]-'0';
            cur *= 2;
        }
        cur /= 2;
        m[i] = cur;
    }

    memset (can,0,sizeof(can));
    for (int i : cari) {
        for (int j=0;j<k;j++) {
            if ((i&(1<<(k-1-j)))) {
                can[i] |= m[j+1];
            }
        }
    }

    int r[n+5];
    memset (r,0,sizeof(r));
    for (int i=1;i<=n;i++) {
        int x,y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            r[i] = k - y;
        } else {
            r[i] = -1;
        }
    }

    int ans = 0;
    memset (t,0,sizeof(t));
    int cur = 1;
    int tempat[105];
    memset (tempat,0,sizeof(tempat));
    for (int i=1;i<=n;i++) {
        if (r[i] == -1) {
            cur++;
        } else {
            // if (cur == 1) {
            //     for (int j : cari) {
            //         if (can[j] & (1<<r[i])) t[j]++;
            //     }
            // }
        }
        tempat[cur] = i; 
    }

    

    int pref[n+5][k+5];
    memset (pref, 0, sizeof(pref));
    for (int i=1;i<=n;i++) {
        if (r[i] != -1) pref[i][r[i]] = 1;
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<20;j++) {
            pref[i][j] = pref[i-1][j] + (r[i] == j);
        }
    }

    for (int i=0;i<=1;i++) {
        for (int j : cari) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[1][skill] = 0;
    for (int l=0;l<20;l++) {
        if (can[skill] & (1 << l)) {
            // cout << pref[tempat[1]][l] << " ";
            dp[1][skill] += pref[tempat[1]][l];
        }
    }
    ans = max(ans, dp[1][skill]);

        // int cnt = 0;
    for (int i=2;i<=cur;i++) {
        // cerr << "euy " << tempat[i-1]+2 << " " << tempat[i] << endl;
        int previ = (i%2)-1;
        if (previ == -1) previ = 1;

        memset (t,0,sizeof(t));
        // for (int tm=tempat[i-1]+2;tm<=tempat[i];tm++) {
        //     if (r[tm] == -1) continue;
        //     for (int j : cari) {
        //         if (can[j] & (1 << r[tm])) {
        //             t[j]++;
        //         }
        //     }
        // }
        for (int l=0;l<20;l++) {
            // cout << r[tm] << endl;
            int rtm = pref[tempat[i]][l]-pref[tempat[i-1]+2-1][l];
            // cout << rtm << endl;
            for (int j : cari) {
                if (can[j] & (1 << l)) {
                    t[j]+=rtm;
                }
            }
        }
        // cout << cnt << endl;
        for (int j : cari) {
            for (int l : adj[j]) {
                if (dp[previ][j] != INT_MIN) {
                    dp[i%2][l] = max(dp[i%2][l], dp[previ][j] + t[l]);
                }
                ans = max(ans, dp[i%2][l]);
            }
        }
    }

    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}