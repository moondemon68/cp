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

int l[2000005], r[2000005];
int a[200005], limit[200005], last[200005];
int len = 2;

bool cmp(pii p, pii q) {
    if (p.fi == q.fi) {
        if (a[p.se+len-1] == a[q.se+len-1]) return p.se < q.se;
        else return a[p.se+len-1] < a[q.se+len-1];
    }
    else return p.fi < q.fi;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];

    for (int i=1;i<=n;i++) {
        limit[i] = n+1;
        limit[last[a[i]]] = i;
        last[a[i]] = i;
    }

    memset (l,-1,sizeof(l));
    memset (r,-1,sizeof(r));

    int cur = 1;
    vector<pii> v;
    for (int i=1;i<=n;i++) {
        v.pb({a[i], i});
    }
    sort (v.begin(), v.end());

    for (int i=1;i<=n;i++) {
        l[cur] = v[i-1].se;
        r[cur] = v[i-1].se;
        cur++;
    }

    int c[n+5];
    memset(c,0,sizeof(c));
    for (int i=1;i<v.size();i++) {
        if (v[i].fi == v[i-1].fi) c[v[i].se] = c[v[i-1].se];
        else c[v[i].se] = c[v[i-1].se] + 1;
    }
    // for (int i=1;i<=n;i++) cout << c[i] << " ";
    // cout << endl;

    while (cur < 1000005) {
        vector<pii> w;
        for (int i=0;i<v.size();i++) {
            if (limit[v[i].se] > v[i].se+len-1 && v[i].se+len-1 <= n) limit[v[i].se] = min(limit[v[i].se], limit[v[i].se+len-1]);
            if (v[i].se+len-1 < limit[v[i].se]) w.pb({c[v[i].se], v[i].se});
        }
        sort (w.begin(), w.end(), cmp);
        memset (c,0,sizeof(c));
        for (int i=1;i<w.size();i++) {
            if (w[i].fi == w[i-1].fi && a[w[i].se+len-1] == a[w[i-1].se+len-1]) c[w[i].se] = c[w[i-1].se];
            else c[w[i].se] = c[w[i-1].se] + 1;
        }
        for (int i=0;i<w.size();i++) {
            l[cur] = w[i].se;
            r[cur] = w[i].se + len - 1;
            cur++;
        }
        len++;
        v.clear();
        for (int i=0;i<w.size();i++) {
            v.pb({c[w[i].se], w[i].se});
        }
        // for (int i=1;i<=cur;i++) cout << l[i] << " ";
        // cout << endl;
        // for (int i=1;i<=cur;i++) cout << r[i] << " ";
        // cout << endl;
        if (len > n) break;
    }


    while (q--) {
        int x;
        cin >> x;
        cout << l[x] << " " << r[x] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}