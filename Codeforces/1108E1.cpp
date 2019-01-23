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
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int l[m+5],r[m+5];
    for (int i=1;i<=m;i++) cin >> l[i] >> r[i];    
    int ans=0,ansi=0,ansj=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==j) continue;
            int maxx=a[j],minx=a[i];
            for (int k=1;k<=m;k++)  {
                if ((i>=l[k]&&i<=r[k])&&!(j>=l[k]&&j<=r[k])) minx--;
            }
            if (maxx-minx>ans) {
                ans=maxx-minx;
                ansi=i;
                ansj=j;
            }
        }
    }
    cout << ans << endl;
    bool y[m+5];
    memset (y,0,sizeof(y));
    for (int i=1;i<=m;i++) {
        if (ansi>=l[i]&&ansi<=r[i]&&!(ansj>=l[i]&&ansj<=r[i])) y[i]=1;
    }
    int cnt=0;
    for (int i=1;i<=m;i++) cnt+=y[i];
    cout << cnt << endl;
    for (int i=1;i<=m;i++) {
        if (y[i]) cout << i << " ";
    }
    return 0;
}
