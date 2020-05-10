#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

pii a[200005];
LL sum[1000005], cnt[1000005];

LL querysum(LL pos) {
    LL ret = 0;
    for (;pos>=0;pos=(pos&(pos+1))-1) {
        ret += sum[pos];
    }
    return ret;
}
LL querycnt(LL pos) {
    LL ret = 0;
    for (;pos>=0;pos=(pos&(pos+1))-1) {
        ret += cnt[pos];
    }
    return ret;
}

void updatesum(LL pos, LL val) {
    for (;pos<1000000;pos|=pos+1) {
        sum[pos] += val;
    }
}
void updatecnt(LL pos, LL val) {
    for (;pos<1000000;pos|=pos+1) {
        cnt[pos] += val;
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    for (LL i=1;i<=n;i++) cin >> a[i].fi;
    for (LL i=1;i<=n;i++) cin >> a[i].se;
    
    vector<LL> v;
    for (LL i=1;i<=n;i++) {
        v.pb(a[i].se);
    }
    sort (v.begin(), v.end());
    map<LL,LL> num;
    for (LL i=0;i<v.size();i++) {
        num[v[i]] = i;
    }
    for (LL i=1;i<=n;i++) {
        a[i].se = num[a[i].se];
    }

    sort (a+1,a+n+1);
    memset (sum,0,sizeof(sum));
    memset (cnt,0,sizeof(cnt));
    LL ans = 0;
    for (LL i=1;i<=n;i++) {
        ans += a[i].fi * querycnt(a[i].se) - querysum(a[i].se);
        updatesum(a[i].se, a[i].fi);
        updatecnt(a[i].se, 1);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}