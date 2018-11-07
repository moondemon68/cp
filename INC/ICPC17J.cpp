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
    int n,k,t;
    cin >> n >> k >> t;
    int a[100005];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    int m=a[k],d=1,u=1;
    for (int i=1;i<=n;i++) {
      if (a[i]<m) d++; else break;
    }
    for (int i=1;i<=n;i++) {
      if (a[i]<=m) u++; else break;
    }
    int ans1=MOD,ans2=MOD,dd=d,uu=u;
    bool y=1;
    int tmp=0;
    while (u-d>1&&y) {
      d++;
      tmp++;
      if (a[d]>0) a[d]--; else y=0;
    }
    if (u-d==1&&y) ans1=tmp;

    y=1;
    tmp=0;
    while (uu-dd>1&&y) {
      uu--;
      tmp++;
      if (a[uu]<t) a[uu]++; else y=0;
    }
    if (uu-dd==1&&y) ans2=tmp;
    if (min(ans1,ans2)==MOD) cout << -1 << endl;
    else cout << min(ans1,ans2) << endl;
    return 0;
}
