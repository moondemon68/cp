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
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    LL ans=0;
    for (int i=1;i<=n/2;i++) {
        ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    }
    cout << ans << endl;
    return 0;
}