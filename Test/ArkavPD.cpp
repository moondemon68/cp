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
    int tc;
    cin >> tc;
    while (tc--) {
      int n,k;
      cin >> n >> k;
      int a[100005];
      for (int i=1;i<=n;i++) cin >> a[i];
      sort (a+1,a+n+1);
      for (int i=1;i<n;i++) cout << a[i+1]-a[i] << " ";
      cout << endl;
    }
    return 0;
}
