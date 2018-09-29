#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int cut(int a[],int l, int r) {
  for (int i=l;i<=r;i++) {

  }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[5005];
    for (int i=1;i<=n;i++) cin >> a[i];
    int mini=INT_MAX;
    for (int i=1;i<=n;i++) mini=min(mini,a[i]);
    for (int i=1;i<=n;i++) a[i]-=mini;
    for (int i=1;i<=n;i++) cout << a[i];
    int ans=cut(a,l,r);
    return 0;
}
