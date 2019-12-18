#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k,n;
    cin >> n >> k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    priority_queue<LL> p;
    LL ans=0;
    for (LL i=1;i<n;i++) {
        p.push(a[i+1]-a[i]);
        ans+=a[i+1]-a[i];
    }
    while (k>1) {
        k--;
        ans-=p.top();
        p.pop();
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}