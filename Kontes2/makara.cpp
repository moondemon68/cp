#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>

using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n+5],b[n+5],c[n+5];
    memset (b,0,sizeof(b));
    memset (c,0,sizeof(c));
    stack<pii> s;
    for (int i=1;i<=n;i++) cin >> a[i];
    a[0]=INT_MAX;
    a[n+1]=INT_MAX;
    for (int i=0;i<=n;i++) {
      if (s.empty()) s.push(mp(a[i],i));
      else {
        while (s.top().fi<a[i]) {
          //cout << s.top().fi << " " << s.top().se << endl;
          s.pop();
        }
        b[i]+=i-s.top().se-1;
        s.push(mp(a[i],i));
      }
    }
    for (int i=n+1;i>=1;i--) {
      if (s.empty()) s.push(mp(a[i],i));
      else {
        while (s.top().fi<a[i]) {
          //cout << s.top().fi << " " << s.top().se << endl;
          s.pop();
        }
        b[i]+=s.top().se-i-1;
        s.push(mp(a[i],i));
      }
    }
    for (int i=1;i<=n;i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}
