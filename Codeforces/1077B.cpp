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
    for (int i=1;i<=n;i++) {
      cin >> a[i];
    }
    int ans=0;
    for (int i=2;i<n;i++) {
      if (a[i]==0&&a[i-1]==1&&a[i+1]==1) {
        ans++;
        a[i+1]=0;
      }
    }
    cout << ans << endl;
    return 0;
}
