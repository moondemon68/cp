#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 10
#define pii pair<int,int>
#define LL long long

using namespace std;

int fastexp(int a,int b) {
  if (b==0) return 1;
  if (b==1) return a;
  else if (b%2==0) return (fastexp(a,b/2)*fastexp(a,b/2))%MOD;
  else return ((fastexp(a,b/2)*fastexp(a,b/2))%MOD*a)%MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      int a,b;
      cin >> a >> b;
      cout << fastexp(a,b) << endl;
    }
    return 0;
}
