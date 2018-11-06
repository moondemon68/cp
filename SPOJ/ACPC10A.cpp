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
      int a,b,c;
      cin >> a >> b >> c;
      if (a==0&&b==0&&c==0) return 0;
      if (b-a==c-b) cout << "AP" << " " << c+b-a << endl;
      else cout << "GP" << " " << c*b/a << endl;
    }
    return 0;
}
