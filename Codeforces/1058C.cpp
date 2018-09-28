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
    int a[105];
    string s;
    cin >> s;
    a[0]=0;
    for (int i=1;i<=n;i++) {
      a[i]=s[i-1]-'0';
      a[i]+=a[i-1];
    }
    /*
    for (int i=1;i<=n;i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    */
    bool y=0;
    for (int i=1;i<=n;i++) {
      int num=a[i],cnt=2,lock=a[i];
      for (int j=i+1;j<=n;j++) {
        if (a[j]==num*cnt) {
          cnt++;
          lock=a[j];
        }
        if (j==n&&a[j]==lock&&(a[i]!=a[j]||a[j]==0)) y=1;
      }
    }
    if (y) cout << "YES";
    else cout << "NO";
    return 0;
}
