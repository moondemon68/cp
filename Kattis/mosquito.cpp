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
    int m,p,l,e,r,s,n;
    while (cin >> m >> p >> l >> e >> r >> s >> n) {
      for (int i=1;i<=n;i++) {
        l+=m*e;
        m=0;
        cout << l << endl;
        p+=l/r;
        l=0;
        cout << p << endl;
        m+=p/s;
        p=0;
        cout <<m << " ";
      }
      cout << m << endl;
    }
    return 0;
}
