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
    LL n,m,k;
    cin >> n >> m >> k;
    if (k==-1&&n%2!=m%2) {
      cout << 0 << endl;
      return 0;
    }
    n--;
    m--;
    cout << poww(poww((LL)2,n),m) << endl;
    return 0;
}
