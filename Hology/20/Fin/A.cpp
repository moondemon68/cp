#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    vector<LL> v;
    pii a[n+5];
    for (LL i=1;i<=n;i++) {
        LL x,y;
        cin >> x >> y;
        a[i] = {x,y};
        v.pb(x);
        v.pb(y+1);
    }
    sort (v.begin(), v.end());
    v.pb(-1);
    vector<LL> v2;
    for (LL i=0;i<v.size()-1;i++) {
        if (v[i] != v[i+1]) v2.pb(v[i]);
    }
    // cout << endl;
    // for (LL i=0;i<v2.size();i++) {
    //     cout << v2[i] << endl;
    // }
    
    map<LL,LL> compress;
    LL ans[2*n+5];
    memset (ans,0,sizeof(ans));
    LL euy[n+5];
    memset (euy,0,sizeof(euy));
    LL x = 0;
    for (LL i=0;i<v2.size();i++) {
        euy[x] = v2[i];
        compress[v2[i]] = x++;
    }

    for (LL i=1;i<=n;i++) {
        // cout << compress[a[i].fi]<< " " << compress[a[i].se] << endl;
        ans[compress[a[i].fi]]++;
        ans[compress[a[i].se+1]]--;
    }
    for (LL i=1;i<=2*n;i++) {
        ans[i] += ans[i-1];
    }
    LL answer[n+5];
    memset (answer,0,sizeof(answer));
    for (LL i=0;i<2*n;i++) {
        answer[ans[i]] += euy[i+1] - euy[i];
    }

    // for (LL i=0;i<=10;i++) cout << ans[i] << ":" << euy[i] << " ";
    // cout << endl;
    for (LL i=1;i<=n;i++) cout << answer[i] << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}