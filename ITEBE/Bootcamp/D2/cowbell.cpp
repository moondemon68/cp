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
    LL n,k;
    cin >> n >> k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
    }
    LL x;
    cin >> x;
    LL c[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> c[i];
    }
    priority_queue<LL,vector<LL>,greater<LL>> pq;
    LL ans=0;
    for (LL i=1;i<=n;i++) {
        pq.push(c[i]);
        while (k < a[i]) {
            if (!pq.empty()) {
                ans+=pq.top();
                pq.pop();
                k+=x;
            } else {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}