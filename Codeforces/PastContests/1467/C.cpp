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

const int MAXN = 300000;
int a[4][MAXN];
int n[4];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n[1] >> n[2] >> n[3];
    int tot = 0;
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=n[i];j++) {
            cin >> a[i][j];
            tot += a[i][j];
        }
    }
    vector<int> a12, a23, a13;
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=n[i];j++) {
            a12.pb(a[i][j]);
        }
    }
    for (int i=2;i<=3;i++) {
        for (int j=1;j<=n[i];j++) {
            a23.pb(a[i][j]);
        }
    }
    for (int i=1;i<=3;i+=2) {
        for (int j=1;j<=n[i];j++) {
            a13.pb(a[i][j]);
        }
    }
    sort(a12.begin(), a12.end());
    sort(a23.begin(), a23.end());
    sort(a13.begin(), a13.end());

    int ans = 0;
    if (n[1] > 1) {
        int tots = 0;
        for (int i=0;i<min((int)a23.size(), n[1]-1);i++) tots += a23[i];
        ans = max(ans, tot - 2 * tots);
        cout << tots << endl;
    }
    if (n[2] > 1) {
        int tots = 0;
        for (int i=0;i<min((int)a13.size(), n[2]-1);i++) tots += a13[i];
        ans = max(ans, tot - 2 * tots);
        cout << tots << endl;
    }
    if (n[3] > 1) {
        int tots = 0;
        for (int i=0;i<min((int)a12.size(), n[3]);i++) tots += a12[i];
        ans = max(ans, tot - 2 * tots);
        cout << tots << endl;
    }
    cout << tot << endl;
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}