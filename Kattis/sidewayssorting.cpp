#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool cmp(string a,string b) {
  for (int i=0;i<a.size();i++) {
    if (a[i]>='A'&&a[i]<='Z') a[i]+=32;
  }
  for (int i=0;i<b.size();i++) {
    if (b[i]>='A'&&b[i]<='Z') b[i]+=32;
  }
  return a<b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1>0) {
      int n,m;
      cin >> n >> m;
      if (n==0&&m==0) return 0;
      char a[20][20];
      for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
          a[i][j]=s[j-1];
        }
      }
      vector<string> ans;
      for (int i=1;i<=m;i++) {
        string s="";
        for (int j=1;j<=n;j++) {
          s+=a[j][i];
        }
        ans.pb(s);
      }
      sort (ans.begin(),ans.end(),cmp);
      for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
          a[j][i]=ans[i-1][j-1];
        }
      }
      for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
      cout << endl;
    }
    return 0;
}
