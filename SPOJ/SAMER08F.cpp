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
    while (1>0) {
      int n;
      cin >> n;
      if (n==0) return 0;
      int ans=0;
      for (int i=1;i<=n;i++) ans+=i*i;
      cout << ans << endl;
    }
    return 0;
}
