#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[n+5][m+5],b[n+5][m+5];
    for (int i=1;i<=n+3;i++) {
        for (int j=1;j<=m+3;j++) {
            a[i][j]=INT_MAX;
            b[i][j]=INT_MAX;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cin >> a[i][j];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cin >> b[i][j];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (b[i][j]<a[i][j]) {
                swap(a[i][j],b[i][j]);
            }
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    bool y=1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<m;j++) {
            if (a[i][j]>=a[i][j+1]) y=0;
        }
    }
    for (int j=1;j<=m;j++) {
        for (int i=1;i<n;i++) {
            if (a[i][j]>=a[i+1][j]) y=0;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<m;j++) {
            if (b[i][j]>=b[i][j+1]) y=0;
        }
    }
    for (int j=1;j<=m;j++) {
        for (int i=1;i<n;i++) {
            if (b[i][j]>=b[i+1][j]) y=0;
        }
    }
    if (y) cout << "Possible"; else cout << "Impossible";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}