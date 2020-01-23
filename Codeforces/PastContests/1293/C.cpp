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
    int n,q;
    cin >> n >> q;
    int a[3][n+5];
    memset(a,0,sizeof(a));
    int cnt = 0;
    while (q--) {
        int x,y;
        cin >> x >> y;
        if (a[x][y] == 1) {
            if (a[3-x][y-1] == 1) cnt--;
            if (a[3-x][y] == 1) cnt--;
            if (a[3-x][y+1] == 1) cnt--;
            a[x][y]=0;
        } else {
            if (a[3-x][y-1] == 1) cnt++;
            if (a[3-x][y] == 1) cnt++;
            if (a[3-x][y+1] == 1) cnt++;
            a[x][y]=1;
        }
        if (cnt == 0) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}