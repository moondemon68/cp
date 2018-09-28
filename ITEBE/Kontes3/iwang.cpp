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
    int a[300005];
    for (int i=1;i<=n;i++) cin >> a[i];
    LL ans=0;
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) {
      ans+=(LL)(i+1)*a[i];
    }
    ans-=a[n];
    cout <<ans << endl;
    return 0;
}
