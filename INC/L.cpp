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
    int n;
    cin >> n;
    int a[25];
    int x=pow(2,n);
    for (int i=1;i<=x;i++) cin >> a[i];
    sort (a+1,a+x+1);
    vector<int> ans;
    for (int i=1;i<=x;i++) {
      if (ans.size()==n) break;
      if (a[i]>0) ans.pb(a[i]);
    }
    if (ans.size()<n) {
      cout << -1 << endl;
      return 0;
    }
    int sum=0;
    for (int i=0;i<n;i++) sum+=ans[i];
    cout << sum << endl;
    return 0;
}
