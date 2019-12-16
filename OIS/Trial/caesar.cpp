#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool eq(string a, string b) {
    int diff = b[0]-a[0];
    for (int i=0;i<a.size();i++) {
        if (a[i] + diff != b[i]) return 0;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,d;
    cin >> n >> d;
    string a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int g[n+5];
    memset (g,-1,sizeof(g));
    for (int i=1;i<=n;i++) {
        if (g[i] == -1) {
            g[i]=i;
            for (int j=i+1;j<=n;j++) {
                if (eq(a[i], a[j])) g[j]=i;
            }
        }
    }
    // for (int i=1;i<=n;i++) cout << g[i] << " ";
    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        cnt[g[i]]++;
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans = max(ans,cnt[i]);
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}