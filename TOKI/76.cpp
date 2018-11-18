#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool a[150][150];

vector<string> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      ans.pb(s);
    }
    int r,c;
    cin >> r >> c;
    int l=max(r,c);
    int p=pow(2,ceil(log2(l)));
    for (int i=0;i<n;i++) {
      int x1=1,y1=1,x2=p,y2=p;
      string t=ans[i];
      for (int j=1;j<t.size();j++) {
        if (t[j]=='0') {
          x2=x1+(x2-x1)/2;
          y2=y1+(y2-y1)/2;
        } else if (t[j]=='2') {
          x1=x1+(x2-x1+1)/2;
          y2=y1+(y2-y1)/2;
        } else if (t[j]=='1') {
          y1=y1+(y2-y1+1)/2;
          x2=x1+(x2-x1)/2;
        } else {
          x1=x1+(x2-x1+1)/2;
          y1=y1+(y2-y1+1)/2;
        }
      }
      for (int x=x1;x<=x2;x++) {
        for (int y=y1;y<=y2;y++) {
          a[x][y]=1;
        }
      }
    }
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
        cout << a[i][j];
        if (j<c) cout << " ";
      }
      cout << endl;
    }
    return 0;
}
