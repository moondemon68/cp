#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pair<LL,LL> a,pair<LL,LL> b) {
    return a.se>b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    pair<LL,LL> a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort (a+1,a+n+1,cmp);
    a[0].fi=0;
    LL ans=0;
    LL sum=0;
    priority_queue<LL,vector<LL>,greater<LL>> p;
    for (int i=1;i<=n;i++) {
        p.push(a[i].fi);
        sum+=a[i].fi;
        while (p.size()>k) {
            sum-=p.top();
            p.pop();
        }
        ans=max(ans,sum*a[i].se);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}