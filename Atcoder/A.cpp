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
    double av=0;
    double a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) av+=a[i];
    av/=n;
    int ans=0;
    double mini=INT_MAX;
    for (int i=1;i<=n;i++) {
      if (abs(a[i]-av)<mini) {
        mini=abs(a[i]-av);
        ans=i;
      }
    }
    cout << ans-1 << endl;
    return 0;
}
