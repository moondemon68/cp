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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        int a[15][35],prize[15],size[15];
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            size[i]=x;
            for (int j=1;j<=x;j++) {
                cin >> a[i][j];
            }
            cin >> prize[i];
        }
        int cnt[35];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=m;i++) cin >> cnt[i];
        int ans=0;
        for (int i=1;i<=n;i++) {
            int get=100000;
            for (int j=1;j<=size[i];j++) {
                get=min(get,cnt[a[i][j]]);
            }
            ans+=get*prize[i];
        }
        cout << ans << endl;
    }    
    return 0;
}
