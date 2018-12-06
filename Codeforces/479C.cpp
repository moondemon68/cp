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
    int n;
    cin >> n;
    pii a[5005];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1);
    int ans=0;
    for (int i=1;i<=n;i++) {
      if (a[i].se>=ans) ans=a[i].se; else ans=a[i].fi;
    }
    cout << ans << endl;
    return 0;
}
