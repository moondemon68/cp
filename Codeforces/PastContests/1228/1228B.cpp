#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL poww(LL a, LL x) {
    LL ret = 1;
    while (x > 0) {
        if (x % 2 == 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        x /= 2;
    }
    return ret % MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    int a[r+5][c+5];
    memset (a,-1,sizeof(a));
    for (int i=1;i<=r;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            if (a[i][j]==0) {
                cout << 0 << endl;
                return 0;
            }
            a[i][j]=1;
        }
        if (a[i][x+1]==1) {
            cout << 0 << endl;
            return 0;
        }
        a[i][x+1]=0;
    }
    for (int i=1;i<=c;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            if (a[j][i]==0) {
                cout << 0 << endl;
                return 0;
            }
            a[j][i]=1;
        }
        if (a[x+1][i]==1) {
            cout << 0 << endl;
            return 0;
        }
        a[x+1][i]=0;
    }
    LL p=0;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]==-1) p++;
        }
    }
    cout << poww(2,p) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}