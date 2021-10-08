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

bool cmp(pii a, pii b) {
    if (a.se == b.se) {
        return a.fi < b.fi;
    } else {
        return a.se > b.se;
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    bool createdStory[m+5][n+5];
    memset(createdStory,0,sizeof(createdStory));
    vector<int> created[m+5];
    vector<int> followed[m+5];
    for (int i=1;i<=n;i++) {
        int creator;
        cin >> creator;
        createdStory[creator][i] = 1;
        created[creator].pb(i);
    }
    int p,q;
    cin >> p >> q;
    bool followUser[m+5][m+5];
    memset(followUser,0,sizeof(followUser));
    bool followStory[m+5][n+5];
    memset(followStory,0,sizeof(followStory));
    while (p--) {
        int i,j;
        cin >> i >> j;
        followUser[i][j] = 1;
    }
    while (q--) {
        int i,j;
        cin >> i >> j;
        followStory[i][j] = 1;
        followed[i].pb(j);
    }
    for (int i=1;i<=m;i++) {
        pii a[n+5];
        for (int k=1;k<=n;k++) {
            a[k] = {k, 0};
        }

        // calc score
        for (int k=1;k<=n;k++) {
            if (createdStory[i][k] || followStory[i][k]) a[k].se = -1;
            else {
                for (int j=1;j<=m;j++) {
                    bool dua = 0, satu = 0;
                    for (auto x : created[j]) {
                        if (followStory[i][x]) dua = 1;
                    }
                    for (auto x : followed[j]) {
                        if (followStory[i][x]) satu = 1;
                    }
                    int ax = 0, bx = 0;
                    if (i == j) ax = 0;
                    else if (followUser[i][j]) ax = 3;
                    else if (dua) ax = 2;
                    else if (satu) ax = 1;
                    else ax = 0;
                    if (createdStory[j][k]) bx = 2;
                    else if (followStory[j][k]) bx = 1;
                    else bx = 0;
                    a[k].se += ax * bx;
                    // cout << i << " " << j << " " << k << " " << ax << " " << bx << endl;
                }
            }
        }

        sort(a+1, a+n+1, cmp);
        // for (int j=1;j<=n;j++) cout << a[j].fi << " " << a[j].se << endl;
        // cout << endl;
        for (int j=1;j<=3;j++) cout << a[j].fi << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}