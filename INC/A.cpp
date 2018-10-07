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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int b,c;
    string s,t;
    cin >> b >> s;
    cin >> c >> t;
    int ansb=0,ansc=0;
    if (s=="right") {
      for (int i=b;i<=n;i++) {
        ansb+=a[i];
      }
    } else {
      for (int i=b;i>=1;i--) {
        ansb+=a[i];
      }
    }
    if (t=="right") {
      for (int i=c;i<=n;i++) {
        if (a[i]==0) ansc++;
      }
    } else {
      for (int i=c;i>=1;i--) {
        if (a[i]==0) ansc++;
      }
    }
    cout << ansb << " " << ansc << endl;
    return 0;
}
