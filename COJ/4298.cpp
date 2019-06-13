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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        bool a[n+5];
        memset (a,0,sizeof(a));
        for (int i=1;i<=m;i++) {
            int x;
            cin >> x;
            a[x]=1;
        }
        for (int i=1;i<=n;i++) {
            if (!a[i]) cout << i << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}