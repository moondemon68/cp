#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int g=a[1];
    for (int i=1;i<=n;i++) g=__gcd(g,a[i]);
    if (g != 1) {
        cout << -1 << endl;
        return 0;
    }
    int one=0;
    for (int i=1;i<=n;i++) {
        if (a[i]==1) one++;
    }
    if (one) {
        cout << n-one << endl;
        return 0;
    }
    int ans=INT_MAX;
    for (int i=1;i<=n;i++) {
        int cnt=1;
        g=a[i];
        for (int j=i+1;j<=n;j++) {
            g=__gcd(g,a[j]);
            cnt++;
            if (g==1) {
                ans=min(ans,cnt);
            }
        }
    }
    ans=ans+n-1;
    cout << ans-1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}