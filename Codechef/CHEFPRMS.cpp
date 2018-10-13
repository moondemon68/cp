#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool p[205];
bool sem(int n) {
  for (int i=2;i<=n;i++) {
    for (int j=i+1;j<=n;j++) {
      if (p[i]&&p[j]&&i*j==n) return 1;
    }
  }
  return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    memset (p,1,sizeof(p));
    for (int i=2;i*i<=200;i++) {
      for (int j=i*i;j<=200;j+=i) {
        p[j]=0;
      }
    }
    while (tc--) {
      int n;
      cin >> n;
      bool y=0;
      for (int i=1;i<n;i++) if (sem(i)&&sem(n-i)) y=1;
      if (y) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    return 0;
}
