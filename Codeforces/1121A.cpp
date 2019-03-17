#include <bits/stdc++.h>

using namespace std;

int main () {
    int n,m,k;
    cin >> n >> m >> k;
    int p[n+5],s[n+5],c[k+5];
    for (int i=1;i<=n;i++) cin >> p[i];
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=1;i<=k;i++) cin >> c[i];
    int maxs[n+5];
    memset (maxs,0,sizeof(maxs));
    for (int i=1;i<=n;i++) {
        maxs[s[i]]=max(maxs[s[i]],p[i]);
    }
    int ans=0;
    for (int i=1;i<=k;i++) {
        if (p[c[i]]!=maxs[s[c[i]]]) ans++;
    }
    cout << ans << endl;
    return 0;
}