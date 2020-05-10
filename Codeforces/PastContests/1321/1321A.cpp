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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int b[n+5];
    for (int i=1;i<=n;i++) cin >> b[i];
    int x=0,y=0;
    for (int i=1;i<=n;i++) {
        if (a[i] == 1 && b[i] == 0) x++;
        else if (a[i] == 0 && b[i] == 1) y++;
    }
    if (x == 0) cout << -1 << endl;
    else if (y % x == 0) cout << y/x+1;
    else cout << (y+x-1)/x;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}