#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
LL poww(LL a,LL b) {
  if (b==0) return 1;
  if (b==1) return a;
  if (b%2==0) return ((poww(a,b/2)%MOD)*(poww(a,b/2)%MOD))%MOD;
  else return ((((poww(a,b/2)%MOD)*(poww(a,b/2)%MOD))%MOD)*a)%MOD;
}
int main () {
    freopen ("b1.in","r",stdin);
    freopen ("b1.out","w",stdout);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n;
      cin >> n;
      string s;
      cin>> s;
      string p;
      cin >> p;
      int tb=0,lr=0;
      for (int i=0;i<n;i++) {
        if (s[i]=='T'||s[i]=='B') tb++; else lr++;
      }
      if (p=="TB"||p=="BT") {
        cout << poww(2,lr)+1 << endl;
      } else cout << poww(2,tb)+1 << endl;
    }
    return 0;
}
