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
    vector<int> a;
    for (int i=1;i<=3;i++) {
      int x;
      cin >> x;
      a.pb(x);
    }
    int ans=0;
    bool y=0;
    while (!y) {
      sort (a.begin(),a.end());
      y=1;
      if ((a[0]+a[1])<=a[2]) {
        ans++;
        a[0]++;
        y=0;
      }
    }
    cout << ans << endl;
    return 0;
}
