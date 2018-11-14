#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool cmp (pair<string,string> a,pair<string,string> b) {
  while (a.se.size()<b.se.size()) a.se+='m';
  while (b.se.size()<a.se.size()) b.se+='m';
  if (a.se==b.se) return a.fi<b.fi;
  else return a.se>b.se;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      int n;
      cin >> n;
      pair<string,string> c[105];
      for (int i=1;i<=n;i++) c[i].se="";
      for (int i=1;i<=n;i++) {
        cin >> c[i].fi;
        string t;
        t="-";
        string s;
        cin >> s;
        t+=s;
        for (int j=t.size()-1;j>=1;j--) {
          if (t[j-1]=='-') c[i].se+=t[j];
        }
        cin >> s;
      }
      sort (c+1,c+n+1,cmp);
      for (int i=1;i<=n;i++) {
        for (int j=0;j<c[i].fi.size()-1;j++) {
          cout << c[i].fi[j];
        }
        cout << endl;
      }
      for (int i=1;i<=30;i++) cout << "=";
      cout << endl;
    }
    return 0;
}
