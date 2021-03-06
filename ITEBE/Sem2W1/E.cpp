// D-Query - MO's Algorithm
#include <bits/stdc++.h>
#define fi first.first
#define se first.second
#define id second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int g[500005],cnt[1000005],a[500005];
pair<pii,int> query[500005];

bool cmp(pair<pii,int> a,pair<pii,int> b) {
    if (g[a.fi]==g[b.fi]) {
        return a.se<b.se;
    } else {
        return g[a.fi]<g[b.fi];
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
        cin >> query[i].fi >> query[i].se;
        query[i].id=i;
    }
    int gcnt=0,group=0;
    for (int i=1;i<=n;i++) {
        g[i]=group;
        gcnt++;
        int x=sqrt(n)+1;
        if (gcnt==x) {
            group++;
            gcnt=0;
        }
    }
    sort (query+1,query+q+1,cmp);
    memset (cnt,0,sizeof(cnt));
    int ans[q+5];
    memset (ans,0,sizeof(ans));
    int l=1,r=1;
    int answer=0;
    for (int t=1;t<=q;t++) {
        //cerr << query[t].fi << query[t].se << endl;
        while ((query[t].se+1)>r) {
            cnt[a[r]]++;
            if (cnt[a[r]]==1) answer++;
            r++;
        }
        while ((query[t].se+1)<r) {
            cnt[a[r-1]]--;
            if (cnt[a[r-1]]==0) answer--;
            r--;
        }
        //for (int i=0;i<=5;i++) cerr << cnt[i];
        //cerr << endl;
        while (query[t].fi>l) {
            cnt[a[l]]--;
            if (cnt[a[l]]==0) answer--;
            l++;
        }
        //for (int i=0;i<=5;i++) cerr << cnt[i];
        //cerr << endl;
        while (query[t].fi<l) {
            cnt[a[l-1]]++;
            if (cnt[a[l-1]]==1) answer++;
            l--;
        }
        //for (int i=0;i<=5;i++) cerr << cnt[i];
        //cerr << endl;
        //cerr << l << r << endl;
        //for (int i=0;i<=5;i++) cerr << cnt[i];
        //cerr << endl;
        ans[query[t].id]=answer;
    }
    for (int i=1;i<=q;i++) cout << ans[i] << "\n";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}