#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool y[30],d[105],valid=1;
vector<string> a;
vector<char> ans[105];

void check(vector<string> a,int p) {
  vector<string> same;
  for (int i=0;i<a.size()-1;i++) {
    //cout << p << a[i] << d[i] << endl;
    if (a[i][p]==a[i+1][p]) {
      same.pb(a[i]);
      d[i]=0;
      if (!y[a[i][p]-'a']) {
        //ans[p].pb(a[i][p]);
        //y[a[i][p]-'a']=1;
      }
    } else if (a[i][p]!=a[i+1][p]) {
      if (same.size()>0) {
        same.pb(a[i]);
        same.pb(".");
        check(same,p+1);
        same.clear();
      }
      if (!y[a[i][p]-'a']&&!d[i]) {
        //cout <<1<< a[i] << endl;
        ans[p].pb(a[i][p]);
        y[a[i][p]-'a']=1;
        d[i]=1;
      }
      else if (y[a[i][p]-'a']) {
        cout << "Impossible" << endl;
        valid=0;
      }
    }
  }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      a.pb(s);
    }
    memset (y,0,sizeof(y));
    memset (d,0,sizeof(d));
    a.pb(".");
    check(a,0);
    if (valid) {
      for (int i=0;i<100;i++) {
        for (int j=0;j<ans[i].size();j++) cout << ans[i][j];
      }
      string g="";
      for (int i=0;i<26;i++) {
        if (!y[i]) g+=(char)i+'a';
      }
      cout << g;
    }

    return 0;
}
/*
4
dicky
novanto
norman
saviero
3
yonas
adiel
wiguna
3
novanto
wiguna
norman
*/
