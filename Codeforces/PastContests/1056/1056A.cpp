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
    int cnt[105];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
      int k;
      cin >> k;
      for (int j=1;j<=k;j++) {
        int x;
        cin >> x;
        cnt[x]++;
      }
    }
    for (int i=1;i<=100;i++) {
      if (cnt[i]==n) cout << i << " ";
    }
    cout << endl;
    return 0;
}
