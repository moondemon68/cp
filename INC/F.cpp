#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool a[55][30];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    memset (a,0,sizeof(a));
    cin.ignore();
    for (int i=1;i<=n;i++) {
      string s;
      getline(cin,s);
      for (int j=0;j<s.size();j++) {
        if (s[j]>='A'&&s[j]<='Z') a[i][s[j]-'A']=1;
      }
    }
    for (int q=1;q<=m;q++) {
      string p;
      cin >> p;

    }
    return 0;
}
