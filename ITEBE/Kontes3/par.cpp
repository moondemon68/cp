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
    LL a,b;
    cin >> a >> b;
    LL c=__gcd(a,b);
    a/=c; b/=c;
    LL aa=a,bb=b;
    LL ans=0;
    while (a>0&&b>0) {
      if (a<b) {
        ans+=b/a;
        b=b%a;
      } else {
        ans+=a/b;
        a=a%b;
      }
      //cout << a << " " << b << endl;
    }
    cout << ans << endl;
    return 0;
}
