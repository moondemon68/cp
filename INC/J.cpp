#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >>n >> m;
    LL a[200005];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    LL ansmax=0,ansmin=0;
    //for (LL i=1;i<=n;i++) cout << a[i] << " ";
    //cout << endl;

    for (int i=1;i<=m;i++) ansmin+=a[i];

    LL l=1,cnt=0;
    while (l<=n&&cnt<n%m) {
      ansmax+=a[l];
      l+=n/m+1;
      cnt++;
      if (cnt==n%m) break;
    }
    while (l<=n) {
      ansmax+=a[l];
      l+=n/m;
    }

    cout << ansmin << " " << ansmax << endl;
    return 0;
}
