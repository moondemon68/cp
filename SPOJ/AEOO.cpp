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
    int ans=0;
    for (int i=1;i<=n;i++) {
      for (int j=i;j<=n;j++) {
        if ((i*j)<=n) ans++;
      }
    }
    cout << ans << endl;
    return 0;
}
