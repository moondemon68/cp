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
    return a.se > b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, f, b;
    cin >> n >> f >> b;
    double a[n+5][f+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=f;j++) {
            cin >> a[i][j];
        }
    }
    double avg[f+5];
    memset(avg,0,sizeof(avg));
    for (int i=1;i<=f;i++) {
        for (int j=1;j<=n;j++) {
            avg[i] += a[j][i];
        }
        avg[i] /= n;
    }
    pii ans[n+5];
    for (int i=1;i<=n;i++) {
        ans[i] = {i, 0};
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=f/2;j++) {
            if (abs(a[i][j] - avg[j]) > abs(a[i][f-j+1] - avg[j])) ans[i].se++;
        }
    }
    sort(ans+1,ans+n+1, cmp);
    // for (int i=1;i<=n;i++) cout << ans[i].fi << " " << ans[i].se << endl;
    for (int i=1;i<=b;i++) cout << ans[i].fi << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}