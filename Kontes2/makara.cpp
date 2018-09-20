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
    for (int i=1;i<=n;i++) {
      if (s.empty()) s.push(make_pair(a[i],i));
      else {
        while (!s.top().fi<a[i]) {
          s.pop();
        }
        b[i]+=i-s.top().second;
      }
    }
    for (int i=1;i<=n;i++) cout << b[i] << " ";
    return 0;
}
