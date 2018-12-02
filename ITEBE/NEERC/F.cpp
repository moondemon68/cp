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
    bool y=1;
    for (int i=2;i*i<=n;i++) {
      if (n%i==0) {
        y=0;
      }
    }
    if (y) {
      cout << "NO" << endl;
      return 0;
    }
    vector<int> f;
    for (int i=2;i*i<=n;i++) {
      if (n%i==0) {
        f.pb(i);
        f.pb(n/i);
      }
    }
    sort (f.begin(),f.end());
    int t=n-1;
    vector<int> p;
    int cnt=0,k=f.size()-1;
    while (t>0) {
      cnt++;
      if (t>=f[k]) {
        t-=f[k];
        p.pb(f[k]);
      } else {
        k--;
        if (k==-1&&t!=0) {
          cnt=234567;
        }
      }
      if (cnt==234567) {
        break;
      }
    }
    if (cnt==234567) {
      cout << "NO" << endl;
      return 0;
    }
    cout << "YES" << endl;
    cout << p.size() << endl;
    for (int i=0;i<p.size();i++) {
      cout << p[i]/__gcd(p[i],n) << " " << n/__gcd(p[i],n) << endl;
    }
    return 0;
}
