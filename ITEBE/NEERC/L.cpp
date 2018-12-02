#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool cmp(pii a,pii b) {
  if (a.fi==b.fi) return a.se>b.se;
  return a.fi>b.fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n>> k;
    pair<int,int> a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi;
    for (int i=1;i<=n;i++) cin >> a[i].se;
    sort (a+1,a+n+1,cmp);
    bool d[k+5];
    memset (d,0,sizeof(d));
    priority_queue<int,vector<int>,greater<int>> p;
    LL ans=0;
    for (int i=1;i<=n;i++) {
      if (!d[a[i].fi]) {
        d[a[i].fi]=1;
      } else {
        p.push(a[i].se);
      }
    }
    for (int i=1;i<=k;i++) {
      if (!d[i]) {
        ans+=p.top();
        p.pop();
      }
    }
    cout << ans << endl;
    return 0;
}
/*
8 7
1 1 3 1 5 3 7 1
5 7 4 8 1 3 5 2
*/
